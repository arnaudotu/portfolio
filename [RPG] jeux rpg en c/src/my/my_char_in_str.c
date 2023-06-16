/*
** EPITECH PROJECT, 2022
** my_char_in_str.c
** File description:
** returns the number of occurence of a character in a string
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns the number of occurence of a character in a string
///\param str String to check
///\param c Character to check
///\return Number of occurence
/////////////////////////////////////////
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
