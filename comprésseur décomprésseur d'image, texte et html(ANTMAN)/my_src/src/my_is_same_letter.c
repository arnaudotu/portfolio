/*
** EPITECH PROJECT, 2022
** my_file_to_str.c
** File description:
** checks two chars to see if they are the same letter (maj included)
*/

#include "../include/my.h"

int my_is_same_letter(char a, char b)
{
    if (a == b || (a + 32 == b || a - 32 == b)) {
        return (1);
    }
    return (0);
}
