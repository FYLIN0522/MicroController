/** @file   movement_check.h
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the functions to check the players state.
*/


#ifndef MOVEMENT_CHECK_H
#define MOVEMENT_CHECK_H


#include "player.h"
#include <stdint.h>


/** Checks if the player is moving while the blue LED is on
    @param player_ptr pointer to the player type
    @param led_state pointer to the blue led state (non-zero for on)
    @param bitmap_ptr pointer to the LED matrix bitmap */
void movement_check(Player* playerPtr, uint8_t led_state, uint8_t* bitmapPtr);


/** Checks if the player has reached the end of the LED matrix
    @param player_ptr pointer to the player type
    @param bitmap_ptr pointer to the LED matrix bitmap */
void win_check(Player* PlayerPtr, uint8_t* bitmapPtr);
#endif