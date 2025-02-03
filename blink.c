// this is the header file that tells the compiler what pins and ports, etc.
// are available on this chip.
#include <avr/io.h>
#include <regportstructs.h>

#include "delay.h"

int main(void)
{
  // initialize the direction of PORTB #0 to be an output
  DDRBbits.ddb0 = 1;

  while (1)
  {
    // turn on the LED for 200ms
    //setbit(PORTD, LED);
    PORTBbits.pb0 = 1;

    delay_ms(50);

    // now turn off the LED for another 200ms
    //clearbit(PORTD, LED);
    PORTBbits.pb0 = 0;

    delay_ms(50);

    // now start over
  }
}
