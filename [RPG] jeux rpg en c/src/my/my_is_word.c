/*
** EPITECH PROJECT, 2022
** my_is_word.c
** File description:
** checks a str to see if it's a full word (letters only)
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks a string to see if it's a full word (letters only)
///\param str String to check
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_word(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_is_letter(str[i])) {
            return (0);
        }
    }
    return (1);
}
