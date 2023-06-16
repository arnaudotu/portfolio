/*
** EPITECH PROJECT, 2022
** flags_printf.c
** File description:
** reiugiuhezo
*/

#include "../include/my.h"

int print_chara (va_list list)
{
    char c = va_arg(list, int);
    my_putchar(c);
}

int print_string (va_list list)
{
    char* s = va_arg(list, char*);
    my_putstr(s);
}

int print_nbr (va_list list)
{
    int d = va_arg(list, int);
    my_putnbr(d);
}

int print_nbrf (va_list list)
{
    int i = va_arg(list, int);
    my_putnbr(i);
}

int print_hexa (va_list list)
{
    int x = va_arg(list, int);
    hexa(x);
}
