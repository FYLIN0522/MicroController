/** @file   game.c
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the implementation of the statues game.

    ENCE260 Embedded Programming Assignment.
    See the README for instructions on how to play.
*/


#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "button.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "led.h"
#include "timer.h"
#include "ledmat.h"
#include "player.h"
#include "macros.h"
#include "blue_led.h"
#include "display_text.h"
#include "movement_check.h"


/** Defines the LED matrix bitmap (5x7) */
static uint8_t bitmap[5];


/** Updates the LED matrix */
void update_display(void)
{
    uint8_t current_column = 0;
    while (current_column < LEDMAT_COLS_NUM) {
        ledmat_display_column(bitmap[current_column], current_column);
        current_column++;
    }
}


/** takes navswitch input from the player and calls player functions to update the players state
    @param player_ptr pointer to the player type */
void navswitch_task(Player* player_ptr)
{
    navswitch_update();

    if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
        if (bitmap[PLAYER_COLUMN] >= 1) {
            move_player(player_ptr);
        }
    }
    if (navswitch_release_event_p(NAVSWITCH_NORTH)) {
        stop_player(player_ptr);
    }
}



/** Initilise all the drivers and the game state */
void init_game(void)
{
    bitmap[PLAYER_COLUMN] = PLAYER_BIT_PATTERN;
    system_init();
    timer_init();
    button_init();
    blue_led_init();    
    navswitch_init();
    pacer_init(PACER_RATE);
    ledmat_init();
    tinygl_init (PACER_RATE);
}


/** Runs the game. */
int main(void)
{

    init_game();
    Player player;
    init_player(&player);


    display_text("START");

    uint16_t tick = 0;
    uint16_t clock = 0;
    while (1)
    {
	    if(player.moving == 1) {
	        bitmap[0] = 255;
	    } else {
	        bitmap[0] = 0;
	    }
        led_task(&tick);
        movement_check(&player, get_led_state(), bitmap);

        navswitch_task(&player);
	    update_player(&player, bitmap);

	    if(tick % (PACER_RATE / DISPLAY_RATE) == 0) {
	        update_display();
	    }

	    if(tick % PACER_RATE == 0) {
	        clock++;
	    }


        win_check(&player, bitmap);

        tick++;
        pacer_wait();
   
    }

}
