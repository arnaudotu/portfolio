/*
** EPITECH PROJECT, 2022
** my_file_to_str.c
** File description:
** checks a str to see if it's a float (must contain a '.')
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks a string to see if it's a float (must contain a '.')
///\param str String to check
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_float(char *str)
{
    int dot_count = 0; int unit_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 || str[i] > 57) && str[i] != '.') {
            return (0);
        }
        if (str[i] == '.') {
            dot_count++;
        } else {
            unit_count++;
        }
    }
    if (dot_count != 1 && unit_count > 0) {
        return (0);
    }
    return (1);
}
