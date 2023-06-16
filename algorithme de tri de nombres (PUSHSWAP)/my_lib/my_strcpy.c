/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** 2
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int mac = 0;
    for (int i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
        mac += 1;
    }
    dest[mac] = '\0';
    return (dest);
}
