/*
** EPITECH PROJECT, 2022
** image_algo.c
** File description:
** algorithm of image compression
*/

#include "../include/antman.h"

int set_i(char **tab)
{
    int i = 3;
    for (int j = 0; tab[j] != NULL; j++) {
        if (tab[i][0] == '#') {
            i++;
        }
    }
    return i;
}

void print_first(char **tab, int lim)
{
    for (int i = 0; i < lim; i++) {
        my_put_str(tab[i]);
        my_put_char('\n');
    }
}

void print_last(char **tab, int i)
{
    my_put_str(tab[i]); my_put_char('\n');
    for (i; tab[i] != NULL; i++) {
        my_put_str(tab[i]); my_put_char('\n');
    }
}

char *get_comp(char **tab, int i)
{
    char *comp = malloc(sizeof(char) * 4);
    my_strcpy(comp, tab[i]);
    my_strcat(comp, " ");
    my_strcat(comp, tab[i + 1]);
    my_strcat(comp, " ");
    my_strcat(comp, tab[i + 2]);
    return (comp);
}

void image_algo(char *str)
{
    char **tab = my_str_to_array(str, "\n");
    int combo = 0; char *comp; int i = set_i(tab); print_first(tab, i);
    int len = my_arraylen(tab);
    while (tab[i] != NULL) {
        if (i + 3 >= len) {
            print_last(tab, i);
            my_free_array(tab); return;
        }
        comp = get_comp(tab, i); combo = 0;
        while (tab[i] != NULL && !my_strcmp(get_comp(tab, i), comp)) {
            combo++; i += 3;
        }
        my_put_str(comp);
        if (combo > 1) {
            my_put_char(' '); my_put_nbr(combo);
        }
        my_put_char('\n'); free(comp);
    }
    my_free_array(tab);
}
