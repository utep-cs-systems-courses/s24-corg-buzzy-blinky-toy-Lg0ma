#include <msp430.h>
#include "led.h"
#include "switches.h"

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITTCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
}

char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_interrupt_handler()
{
    
}