#include <stdbool.h>

#define ARTIK_PIN_TRUE true
#define ARTIK_PIN_FALSE false


int pinState(port_value, pin_mask)
{
  if(port_value & pin_mask)
  {
    return ARTIK_PIN_TRUE;
  }
  return ARTIK_PIN_FALSE;
}
