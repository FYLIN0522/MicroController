/** @file   movement_check.c
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the functions to check the players state.
*/


#include "macros.h"
#include "movement_check.h"
#include "display_text.h"
#include "player.h"
#include <stdint.h>


char score[MAXIMUM_SCORE_STRING_LENGTH]; /** Buffer for player score string */


/** Checks if the player is moving while the blue LED is on 
    @param player_ptr pointer to the player type
    @param led_state pointer to the blue led state (non-zero for on)
    @param bitmap_ptr pointer to the LED matrix bitmap */
void movement_check(Player* player_ptr, uint8_t led_state, uint8_t* bitmap_ptr)
{
    if ((player_ptr->moving == 1) && (led_state == 1))
    {
        bitmap_ptr[PLAYER_COLUMN] = PLAYER_BIT_PATTERN;
        display_text("FAIL");
        player_score(player_ptr, score);
        display_text(score);
        init_player(player_ptr);
    }
}


/** Checks if the player has reached the end of the LED matrix
    @param player_ptr pointer to the player type
    @param bitmap_ptr pointer to the LED matrix bitmap */
void win_check(Player* player_ptr, uint8_t* bitmap_ptr)
{
    if(bitmap_ptr[PLAYER_COLUMN] <= 0) {
        display_text("WIN");
        player_score(player_ptr, score);
        display_text(score);  // display player score
	    init_player(player_ptr);
    }
}