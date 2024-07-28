#include <Arduino.h>
#include <lvgl.h>

#include "lovyanGfxSetup.h"

#include "ui/ui.h"

#define LED_OUTPUT_PIN 11
#define BUZZER_OUTPUT_PIN 17

#define PWM_LED_PIN 12
#define PWM_CHANNEL 0

#define ANALOG_INPUT_PIN 13

#define TFT_HOR_RES SCREEN_WIDTH
#define TFT_VER_RES SCREEN_HEIGHT

/* LVGL draws into this buffer, 1/10 screen size usually works well. The size is in bytes. */
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

uint32_t draw_buf[DRAW_BUF_SIZE / 4];

LGFX tft;

extern lv_event_t g_eez_event;
extern bool g_eez_event_is_available;

#if LV_USE_LOG != 0
void my_print(lv_log_level_t level, const char *buf)
{
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
#endif

/* LVGL calls it when a rendered image needs to copied to the display. */
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)px_map, w * h);
  tft.endWrite();

  /* Call it to tell LVGL you are ready. */
  lv_disp_flush_ready(disp);
}

/* Read the touchpad. */
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;
  bool touched = tft.getTouch(&touchX, &touchY);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
  else
  {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = touchX;
    data->point.y = touchY;
#if 0
    Serial.printf("x: %03d, y: %03d\n", data->point.x, data->point.y);
#endif
  }
}

void setup()
{
  String LVGL_Arduino = "Hello Arduino ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  Serial.begin(115200);
  Serial.println(LVGL_Arduino);

  tft.begin();
  tft.setRotation(0);
  tft.setBrightness(32);

  lv_init();

  /* Set a tick source so that LVGL will know how much time elapsed. */
  lv_tick_set_cb((lv_tick_get_cb_t)millis);

  /* Register print function for debugging. */
#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print);
#endif

  /* Create a display. */
  lv_display_t *disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_flush_cb(disp, my_disp_flush);
  lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

  /* Initialize the (dummy) input device driver. */
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); /*Touchpad should have POINTER type*/
  lv_indev_set_read_cb(indev, my_touchpad_read);

  Serial.println("Setup done");

#if 0
  /* Create a simple label. */
  lv_obj_t *label = lv_label_create( lv_scr_act() );
  lv_label_set_text( label, "Hello Arduino, I'm LVGL!" );
  lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
#endif

  ui_init();

  pinMode(LED_OUTPUT_PIN, OUTPUT);
  digitalWrite(LED_OUTPUT_PIN, LOW);

  pinMode(BUZZER_OUTPUT_PIN, OUTPUT);
  digitalWrite(BUZZER_OUTPUT_PIN, LOW);

  pinMode(PWM_LED_PIN, OUTPUT);
  ledcAttachPin(PWM_LED_PIN, PWM_CHANNEL);
  ledcSetup(PWM_CHANNEL, 4000, 8); // 4 kHz PWM, 8-bit resolution
  ledcWrite(PWM_CHANNEL, 0);
}

void loop()
{
  lv_task_handler(); /* Let LVGL do its work. */
  ui_tick();

  static boolean setBuzzerFlag = false;

  if (g_eez_event_is_available == true)
  {
    lv_obj_t *obj = lv_event_get_target_obj(&g_eez_event);
    Serial.printf("Received event from obj: %u\n", obj);
    g_eez_event_is_available = false;

    if (obj == objects.main00_btn_next)
    {
      lv_scr_load(objects.screen00);
      setBuzzerFlag = true;
    }
    else if (obj == objects.screen00_btn_back)
    {
      lv_scr_load(objects.main);
      setBuzzerFlag = true;
    }
    else if (obj == objects.screen00_btn_led)
    {
      static boolean ledStatus = LOW;
      ledStatus = !ledStatus;
      digitalWrite(LED_OUTPUT_PIN, ledStatus);
      setBuzzerFlag = true;
    }
    else if (obj == objects.screen00_btn_next)
    {
      lv_scr_load(objects.screen01);
      setBuzzerFlag = true;
    }
    else if (obj == objects.screen01_btn_back)
    {
      lv_scr_load(objects.screen00);
      setBuzzerFlag = true;
    }
    else if (obj == objects.screen01_arc_pwm)
    {
      int32_t val = lv_arc_get_value(objects.screen01_arc_pwm);
      ledcWrite(PWM_CHANNEL, val);

      Serial.printf("arc val: %3d%%\n", (uint16_t)val);
      char labelPwmVal[5] = {0};
      sprintf(labelPwmVal, "%3d%%", (uint16_t)val);
      lv_label_set_text(objects.screen01_label_pwm, labelPwmVal);
    }
    else if (obj == objects.screen01_btn_next)
    {
      lv_scr_load(objects.screen02);
      setBuzzerFlag = true;
    }
    else if (obj == objects.screen02_btn_back)
    {
      lv_scr_load(objects.screen01);
      setBuzzerFlag = true;
    }
  }

  // ========== Buzzer beeper START ==========
  static uint32_t buzzerTimePrev = 0L;
  static boolean buzzerIsBusy = false;

  if (setBuzzerFlag && !buzzerIsBusy)
  {
    buzzerTimePrev = millis();
    setBuzzerFlag = false;
    buzzerIsBusy = true;
    digitalWrite(BUZZER_OUTPUT_PIN, HIGH);
  }

  if (buzzerIsBusy && millis() - buzzerTimePrev > 75) // Beep duration: 75 ms only.
  {
    buzzerIsBusy = false;
    digitalWrite(BUZZER_OUTPUT_PIN, LOW);
  }
  // ========== Buzzer beeper END   ==========

  // ========== ADC input START ==========
  if (lv_screen_active() == objects.screen02) // Run this block only when the current screen is Screen02.
  {
    static int intPotValPrev = analogRead(ANALOG_INPUT_PIN); // Get an initial baseline value.

    int potValCur = analogRead(ANALOG_INPUT_PIN); // Get the current raw value.
    if (abs(potValCur - intPotValPrev) > 5)       // Update the objects only when a delta of 5 units is detected.
    {
      int32_t mappedVal = map(potValCur, 0, 4095, 0, 100); // Get the scaled or mapped value.
      Serial.printf("potValCur: %ld\n", potValCur);
      Serial.printf("mappedVal: %ld\n\n", mappedVal);

      lv_bar_set_value(objects.screen02_bar_horizontal, potValCur, LV_ANIM_OFF);
      lv_bar_set_value(objects.screen02_bar_vertical, mappedVal, LV_ANIM_OFF);

      char labelText[6] = {};
      sprintf(labelText, "%04d", potValCur);
      lv_label_set_text(objects.screen02_label_horizontal, labelText);

      sprintf(labelText, "%3d%%", mappedVal);
      lv_label_set_text(objects.screen02_label_vertical, labelText);

      intPotValPrev = potValCur;
    }
  }
  // ========== ADC input END   ==========
}
