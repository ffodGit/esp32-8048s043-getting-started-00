#include <stdbool.h>
#include "actions.h"

lv_event_t g_eez_event = {};
bool g_eez_event_is_available = false;

void action_set_global_eez_event(lv_event_t *e)
{
    g_eez_event = *e;
    g_eez_event_is_available = true;
}