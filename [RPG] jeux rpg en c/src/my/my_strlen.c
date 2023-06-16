/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** returns the length of a str
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns a string's length
///\param str String to check
///\return Number of characters in the string
/////////////////////////////////////////
int my_strlen(char *str)
{
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return (n);
}
