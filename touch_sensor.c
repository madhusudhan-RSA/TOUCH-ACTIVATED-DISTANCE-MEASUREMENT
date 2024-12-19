#include <avr/io.h>
#include <util/delay.h>

#define TRUE 1
#define FALSE 0
#define TOUCH_SENSOR PA2

void touchSensorInit()
{
  DDRA &= ~(1<<PA2);
  PORTA &= ~(1<<PA2);
}

uint8_t touchSensorDebounce()
{
  uint8_t state1, state2;
  
  state1 = PINA&(1<<PA2);
  _delay_ms(50);
  state2 = PINA&(1<<PA2);
  if(state1 && state2)
  {
    return TRUE;
  }
  return FALSE;
}
