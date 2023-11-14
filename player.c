/** @file   player.c
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the player type and its functions.
*/


#include "player.h"
#include "macros.h"
#include <stdio.h>


#define MAX_PLAYER_SPEED 6          // MAX_PLAYER_SPEED
#define LEDMAT_DISTANCE (65536 / 8) // Abstract distance between LED's

/** Initialises a player
    @param  player_ptr pointer to the player type */
void init_player(Player* player_ptr)
{
    player_ptr->speed = 0;
    player_ptr->position = 0;
    player_ptr->bitmap_position = PLAYER_BIT_PATTERN;
    player_ptr->moving = 0;
}


/** Updates the players abstract position, LED matrix position,
    and moving flag, based on its current speed
    @param  player_ptr pointer to the player type
    @param  bitmap_ptr pointer to the LED matrix bitmap */
void update_player(Player* player_ptr, uint8_t* bitmap_ptr)
{
    player_ptr->position += player_ptr->speed;
    uint8_t offset = (uint8_t)(player_ptr->position / LEDMAT_DISTANCE);
    player_ptr->bitmap_position = PLAYER_BIT_PATTERN >> offset;
    bitmap_ptr[PLAYER_COLUMN] = player_ptr->bitmap_position;
}


/** Sets the players speed and moving flag to 0
    @param  player_ptr pointer to the player type */
void stop_player(Player* player_ptr)
{
    player_ptr->speed = 0;
    player_ptr->moving = 0;
}


/** Sets the players speed and changes the moving flag to 1 
    @param  player_ptr pointer to the player type */
void move_player(Player* player_ptr)
{
    player_ptr->speed = MAX_PLAYER_SPEED;
    player_ptr->moving = 1;
}


/** Converts the players current score to a string
    @param  player_ptr pointer to the player type
    @param  score_ptr pointer to the players score */
void player_score(Player* player_ptr, char* score_ptr)
{
    sprintf(score_ptr, "Your score: %um", player_ptr->position);
}