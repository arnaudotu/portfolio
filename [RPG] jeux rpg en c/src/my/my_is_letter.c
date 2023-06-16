/*
** EPITECH PROJECT, 2022
** my_is_letter.c
** File description:
** checks a str to see if it's a letter
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks a string to see if it's a letter
///\param str String to check
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_letter(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
        return (1);
    }
    return (0);

}
