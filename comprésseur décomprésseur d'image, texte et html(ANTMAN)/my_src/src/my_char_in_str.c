/*
** EPITECH PROJECT, 2022
** my_char_in_str.c
** File description:
** returns the number of occurence or a character in a string
*/

#include "../include/my.h"

int my_char_in_str(char *str, char c)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            n++;
        }
    }
    return (n);
}
