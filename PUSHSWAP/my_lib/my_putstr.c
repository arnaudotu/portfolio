/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** 2
*/

#include <unistd.h>

void *my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0'){
        write (1, &str[i], 1);
        i = i + 1;
    }
    return (0);
}
