/*
** EPITECH PROJECT, 2022
** print f
** File description:
** my_printf
*/

#include <stdarg.h>
#include "includes.h"

void my_putchar_bis(va_list args)
{
    char c = (char)va_arg(args, int);
    my_putchar(c);
}

void my_putstr_bis(va_list args)
{
    char *str = (char *)va_arg(args, char*);
    my_putstr(str);
}

void my_put_nbr_bis(va_list args)
{
    int nb = (int)va_arg(args, int);
    my_putnbr(nb);
}

void loop (char *format, char *flags, va_list args, int i)
{
    void (*fptr_tab[5])(va_list) = {&my_putchar_bis, &my_putstr_bis,
        &my_put_nbr_bis, &my_put_nbr_bis, &my_putchar_bis};
    for (int j = 0; flags[j] != '\0'; j++) {
        if (format[i] == flags[j]) {
            (*fptr_tab[j])(args);
        }
    }
}

int my_printf (char *format, ...)
{
    va_list args;
    va_start(args, format);
    void (*fptr_tab[5])(va_list) = {&my_putchar_bis, &my_putstr_bis,
        &my_put_nbr_bis, &my_put_nbr_bis, &my_putchar_bis};
    char *flags = "csdi%";
    int j;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            loop (format, flags, args, i);
        } else {
            my_putchar(format[i]);
        }

    if (format[i] == '%')
        my_putchar('%');
    }
    va_end(args);
    return j;
}
