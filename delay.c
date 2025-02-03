
#include <avr/io.h>

// this is just a program that 'kills time' in a calibrated method
void delay_ms(uint8_t ms) 
{
  uint16_t delay_count = CLOCK / 17500;
  volatile uint16_t i;

  while (ms != 0) 
  {
    for (i=0; i != delay_count; i++);
    ms--;
  }
}

