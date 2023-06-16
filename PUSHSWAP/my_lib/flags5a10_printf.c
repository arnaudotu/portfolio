/*
** EPITECH PROJECT, 2022
** flag5a10_printf.c
** File description:
** ieiygedjoidz
*/

#include "../include/my.h"

int print_hexa_maj (va_list list)
{
    int X = va_arg(list, int);
    hexa_maj(X);
}

int print_octal (va_list list)
{
    int o = va_arg(list, int);
    octal(o);
}

int print_binary (va_list list)
{
    int b = va_arg(list, int);
    binary(b);
}

int print_bigstr (va_list list)
{
    char* S = va_arg(list, char*);
    my_putstr_maj(S);
}

int print_unsign_dec (va_list list)
{
    int u = va_arg(list, int);
    my_putnbr_u(u);
}
