/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverses a str
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Reverses a string's content
///\param str String to reverse
/////////////////////////////////////////
void my_revstr(char *str)
{
    int len = my_strlen(str);
    char c;
    for (int i = 0; i < (len / 2); i++) {
        c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
}
