/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compares two str and check if they are the same
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Compares two str and check if they are the same
///\param s1 First string to compare
///\param s2 Second string to compare
///\return 0 if they're the same, number of different characters if not
/////////////////////////////////////////
int my_strcmp(char *s1 , char *s2)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);
    if (size_s1 < size_s2) {
        return (-1);
    }
    if (size_s1 > size_s2) {
        return (1);
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (-1);
    }
    return (0);
}
