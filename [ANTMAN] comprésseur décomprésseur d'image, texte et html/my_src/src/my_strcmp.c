/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** compares two str and check if they are the same
*/

#include "../include/my.h"

int my_strcmp(char *s1 , char *s2)
{
    if (s1 == NULL || s2 == NULL) {
        return (1);
    }
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
