#include<avr/io.h>
#include<util/delay.h>

#define TRIGGER PA0
#define ECHO PA1

void UltrasonicInit()
{
  DDRA |= (1 << TRIGGER);
  PORTA &= ~(1 << TRIGGER);
  DDRA &= ~(1 << ECHO);
}

void triggerUltrasonic()
{
  PORTA |= (1 << TRIGGER);
  _delay_us(10);
  PORTA &= ~(1 << TRIGGER);
}

uint16_t echoUltrasonicDuration()
{
  TCCR1B |= ((1 << CS11) | (1 << CS10));
  TCNT1 = 50536;
  while (PINA & (1 << ECHO));
  return (TCNT1-50536);
}

double distanceUltrasonic()
{
  uint16_t duration;
  
  triggerUltrasonic();
  while (!(PINA & (1 << ECHO)));
  duration = echoUltrasonicDuration();
  return(duration*4/58.0);
}
