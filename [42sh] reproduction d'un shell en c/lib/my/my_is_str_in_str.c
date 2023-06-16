/*
** EPITECH PROJECT, 2022
** my_is_str_in_str.c
** File description:
** checks if a str is in a str
*/

#include "includes.h"

int compare_words(char *str, char *elem, int i)
{
    int j = 0;
    while (elem[j] != '\0' && str[i + j] != '\0') {
        if (elem[j] != str[i + j]) {
            return (0);
        }
        j++;
    }
    if (j != my_strlen(elem)) {
        return (0);
    }
    return (1);
}

/////////////////////////////////////////
// Checks if a string is in a string
///\param str String to check
///\param elem String to compare
///\return 1 if true, 0 if false
/////////////////////////////////////////
// Prefer putting that in a .h file. Moreover, this function exists as
// my_str_find. Simply check if my_str_finc(string, sub_string) != -1
// Actualy, this make a C-G2 minor coding style error, due to comments
int my_is_str_in_str(char *str, char *elem)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (compare_words(str, elem, i)) {
            return (1);
        }
    }
    return (0);
}
