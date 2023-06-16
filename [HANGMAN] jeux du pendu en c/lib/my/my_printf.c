/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "lib.h"

int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(const char *str);

int flage(const char *format, int i, va_list args)
{
    int(*tabfpt[21])(va_list args) = {&pourcent, &pours, &pourdi, &pourdi,
        &pourui, &u_octal, &pourc, &pourn, &octal, &hexaint,
        &hexaint, &pourb, &pourhi, &pourhi, &pourli, &pourli, &pourlli,
        &pourlli, &pourhu, &pourllu, &pourf};
    char *a[] = {"%", "s", "d", "i", "u",
        "O", "c", "n", "o", "x", "X", "b",
        "hi", "hd", "li", "ld", "lli","lld", "hu", "llu", "f",""};
    for (int v = 0;a[v][0] != '\0'; v++) {
        int lenarg = my_strlen(a[v]);
        if (my_strncmp(&format[i] , a[v], lenarg) == 0) {
            (tabfpt[v]) (args);
            i += (lenarg - 1);
        }
    }
    return i;
}

int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = flage(format, i + 1, args);
        else {
            my_putchar(format[i]);
        }
    }
}
