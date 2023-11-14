/** @file   blue_led.h
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the blue LED functions
*/


#ifndef BLUE_LED_H
#define BLUE_LED_H
#include <stdint.h>
#include "player.h"


uint8_t led_state; /* blue led state (non-zero for on) */


/** Initialises the blue LED */
void blue_led_init(void);


/** Returns the current state of the blue LED (non-zero for on) */
uint8_t get_led_state(void);


/** Toggles the state of the blue LED */
void blue_led_set(void);


/** Implements the abstraction of the blue LED randomly checking for movement.
    every TOTAL_EVENT_TICKS the LED will randomly select a time window to look for movement.
    @param  tick_ptr pointer to the games current tick */
void led_task(uint16_t* tick_ptr);
#endif