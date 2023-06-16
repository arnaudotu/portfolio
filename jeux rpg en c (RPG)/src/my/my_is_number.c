/*
** EPITECH PROJECT, 2022
** my_is_number.c
** File description:
** checks a str to see if it's a full number
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks a string to see if it's a full number
///\param str String to check
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return (0);
        }
    }
    return (1);
}
