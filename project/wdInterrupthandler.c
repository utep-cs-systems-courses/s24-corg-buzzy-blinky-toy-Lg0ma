#include <msp430.h>
#include "stateMachines.h"

int secondcount = 0;

void
__interrupt_vec(WDT_VECTOR) WDT() 
{
  secondcount++;
    if (secondcount == 125) {
        blink_count = 0;
        P1OUT ^= LED_GREEN;		/* toggle green LED */
        P1OUT ^= LED_RED;
    }
}