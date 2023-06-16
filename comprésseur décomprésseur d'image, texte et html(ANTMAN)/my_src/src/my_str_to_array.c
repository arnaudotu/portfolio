/*
** EPITECH PROJECT, 2022
** my_str_to_array.c
** File description:
** turns a str into a array based on sep symbols
*/

#include "../include/my.h"

int is_a_sep(char c, char *sep)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (c == sep[i]) {
            return (1);
        }
    }
    return (0);
}

int elem_length(char *str, int i, char *sep)
{
    int n = 0;
    for (i; !is_a_sep(str[i], sep) && str[i] != '\0'; i++) {
        n++;
    }
    return (n);
}

int number_elem(char *str, char *sep)
{
    int n = 0; int i = 0;
    while (str[i] != '\0') {
        if (!is_a_sep(str[i], sep)) {
            n++;
            i += elem_length(str, i, sep) - 1;
        }
        i++;
    }
    return (n);
}

char **my_str_to_array(char *str, char *sep)
{
    char **tab = malloc(sizeof(char*) * (number_elem(str, sep) + 1));
    int word = 0; int letter = 0; int i = 0;
    while (is_a_sep(str[i], sep) && str[i] != '\0') {
        i++;
    }
    while (str[i] != '\0') {
        tab[word] = malloc(sizeof(char) * (elem_length(str, i, sep) + 1));
        letter = 0;
        while (!is_a_sep(str[i], sep) && str[i] != '\0') {
            tab[word][letter] = str[i];
            letter++; i++;
        }
        tab[word][letter] = '\0'; word++;
        while (is_a_sep(str[i], sep) && str[i] != '\0') {
            i++;
        }
    }
    tab[word] = NULL;
    return (tab);
}
