/** @file   display_text.c
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the function to render menu text.
*/


#include <stdint.h>
#include "display_text.h"
#include "macros.h"
#include "button.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "pacer.h"


uint8_t game_state = 0; /* Game state (non-zero for start) */


/** Renders the given string onto the LED matrix until BUTTON1 pressed.
    @param string character string to be rendered*/
void display_text(char* string)
{ 
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(string);
    

    /* push button to start the game.*/
    while(game_state == 0)
    {
        pacer_wait();
        tinygl_update();
        button_update();

        if(button_push_event_p(BUTTON1)) { 
            game_state = 1;
            tinygl_clear();
        }
    }

    game_state = 0;
}