#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"

void state_advance(int state) {
  leds_off();
  
  switch(state) {
  case 1:
    red_led_on();
    music();
    leds_off();
    break;
  case 2:
    led_flash();
    leds_off();
    break;
  case 3:
    police_siren();
    leds_off();
    break;
  case 4:
    red_led_on();
    star_wars();
    leds_off();
    break;
  default:
    green_led_on();
    break;
  }
  // Turn on the green led to indicate it's ready for the next step.
  green_led_on();
}