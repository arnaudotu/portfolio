/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** writes a char on the terminal
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Writes a character on the terminal
///\param c Character to write
/////////////////////////////////////////
void my_putchar(char c)
{
    write(1, &c, 1);
}
