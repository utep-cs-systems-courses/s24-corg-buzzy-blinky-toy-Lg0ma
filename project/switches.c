#include <msp430.h>
#include "led.h"
#include "switches.h"

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITTCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interrupt_handler();
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
    char p2val = switch_update_interrupt_sense();
    char sw_button_1 = (p2val & SW1) ? 0 : SW1;
    char sw_button_2 = (p2val & SW2) ? 0 : SW2;
    char sw_button_3 = (p2val & SW3) ? 0 : SW3;
    char sw_button_4 = (p2val & SW4) ? 0 : SW4;

    if (sw_button_1) 
    {
    state_advance(1);
    switch_state_down = 1;
    } 
    else if (sw_button_2) 
    {
      state_advance(2);
      switch_state_down = 1;
    } 
    else if (p2val & SW3 ? 0 : 1) 
    {
      state_advance(3);
      switch_state_down = 1;
    } 
    else if (p2val & SW4 ? 0 : 1)
    {
      state_advance(4);
      switch_state_down = 1;
    }
}