/** @file   macros.h
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines Common macros used in multiple .c files.
*/


#ifndef MACROS_H
#define MACROS_H


#define PLAYER_BIT_PATTERN 0x40     /* Player row bit pattern on LED matrix */
#define PLAYER_COLUMN 2             /* Player column index on LED matrix */
#define REACTION_FLASH_DURATION 4   /* Duration of led flash signalling player to stop */
#define REACTION_TICK_TOLERANCE 10  /* Spacing between two potential LED events, in ticks */
#define REACTION_TIME 350           /* Given time for the player to stop, in ms */
#define REACTION_TICKS REACTION_TIME / (1000 / PACER_RATE) /* Given time for the player to stop, in ticks */
#define STOPPING_TIME 500           /* Time the blue LED is lit, in ms */
#define STOPPING_TICKS STOPPING_TIME / (1000 / PACER_RATE) /* Time the blue LED is lit, in ticks */
#define TOTAL_EVENT_TICKS 1500      /* Length of the LED stop event in ticks */
#define PACER_RATE 500              /* Pacer loop - controls main loop */
#define DISPLAY_RATE 250            /* Display rate */
#define MESSAGE_RATE 10             /* Text scrolling speed */
#define MAXIMUM_SCORE_STRING_LENGTH 50 /* Maximum length for the score string buffer. */
#endif