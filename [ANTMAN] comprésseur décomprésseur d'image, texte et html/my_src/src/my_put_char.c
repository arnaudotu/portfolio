/*
** EPITECH PROJECT, 2022
** my_put_char
** File description:
** writes a char on the terminal
*/

#include "../include/my.h"

void my_put_char(char c)
{
    write(1, &c, 1);
}
