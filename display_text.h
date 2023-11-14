/** @file   display_text.h
    @author Christopher Stewart (21069553) && Fuyi Lin (42735559).
    @date   17 Oct 2021
    @brief  Defines the function to render menu text.
*/


#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H


/** Renders the given string onto the LED matrix until BUTTON1 pressed.
    @param string character string to be rendered*/
void display_text(char* string);
#endif