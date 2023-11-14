/** @file   blue_led.c
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the blue LED functions
*/


#include "blue_led.h"
#include "led.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>


/** Initialises the blue LED */
void blue_led_init(void)
{
    led_init();
    led_set(LED1, led_state);
}


/** Returns the current state of the blue LED (non-zero for on) */
void blue_led_set(void)
{
    led_state = !led_state;
    led_set(LED1, led_state);  
}


/** Toggles the state of the blue LED */
uint8_t get_led_state(void)
{
    return led_state;
}


/** Implements the abstraction of the blue LED randomly checking for movement.
    Every TOTAL_EVENT_TICKS the LED will randomly select a time window to look for movement.
    @param  tick_ptr pointer to the games current tick */
void led_task(uint16_t* tick_ptr)
{
    static uint16_t event_tick = 0;
    static const uint16_t min_ticks = REACTION_TICKS + REACTION_TICK_TOLERANCE;

    if(event_tick == 0) {
	    event_tick = min_ticks + (rand() % (TOTAL_EVENT_TICKS - STOPPING_TICKS - min_ticks));
    }

    uint16_t tick = *tick_ptr;
    if (tick >= TOTAL_EVENT_TICKS) {
        *tick_ptr = 0;
	    event_tick = 0;
    }

    if(tick == event_tick) {
	    blue_led_set();
    } else if(tick == event_tick + STOPPING_TICKS) {
	    blue_led_set();
    }

    if (led_state == 0 && tick == event_tick - REACTION_TICKS) {
        led_set(LED1, 1);
    }
    else if (led_state == 0 && tick == event_tick - REACTION_TICKS + REACTION_FLASH_DURATION) {
        led_set(LED1, 0);
    }
}