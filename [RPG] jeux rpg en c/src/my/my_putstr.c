/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** writes a str on the terminal
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Writes a string on the terminal
///\param str String to write
/////////////////////////////////////////
void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
