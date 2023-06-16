/*
** EPITECH PROJECT, 2022
** flags10a15_printf.c
** File description:
** ieziofehfue
*/

#include "../include/my.h"

int print_pointeur (va_list list)
{
    int p = va_arg(list, int);
    my_put_pointeur(p);
}

int print_float(va_list list)
{
    double f = va_arg(list, double);
    my_put_float(f);
}
