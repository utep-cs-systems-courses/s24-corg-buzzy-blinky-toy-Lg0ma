#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init() {
  P1DIR |= LEDS;
  led_changed = 1;
  led_update();
}

void green_led_on() {
  P1OUT |= LED_RED;
  __delay_cycles(500000);
}

void red_led_on() {
  P1OUT |= LED_GREEN;
  __delay_cycles(500000);
}

void leds_off() {
  P1OUT &= ~LED_GREEN;
  __delay_cycles(500000);
  P1OUT &= ~LED_RED;
}