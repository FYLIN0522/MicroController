/** @file   player.h
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the player type and its functions.
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>


/** Player type */
typedef struct player_s {
    uint8_t speed;
    uint16_t position;
    uint8_t bitmap_position;
    uint8_t moving;
} Player;


/** Initialises a player
    @param  playerPtr pointer to the player type */
void init_player(Player* player_ptr);


/** Updates the players abstract position, LED matrix position,
    and moving flag, based on its current speed
    @param  player_ptr pointer to the player type
    @param  bitmap_ptr pointer to the LED matrix bitmap */
void update_player(Player* player_ptr, uint8_t* bitmap_ptr);


/** Sets the players speed and moving flag to 0
    @param  player_ptr pointer to the player type */
void stop_player(Player* player_ptr);


/** Sets the players speed and changes the moving flag to 1 
    @param  player_ptr pointer to the player type */
void move_player(Player* player_ptr);


/** Converts the players current score to a string
    @param  player_ptr pointer to the player type
    @param  score_ptr pointer to the players score string */
void player_score(Player* player_ptr, char* score_ptr);
#endif