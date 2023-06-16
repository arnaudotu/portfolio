/*
** EPITECH PROJECT, 2022
** image_algo.c
** File description:
** algorithm of image compression
*/

#include "../include/giantman.h"

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

void print_element(char **elem)
{
    int combo;
    if (elem[3] == NULL) {
            combo = 1;
    } else {
        combo = my_str_to_int(elem[3]);
    }
    for (int j = 0; j < combo; j++) {
        my_put_str(elem[0]); my_put_char('\n');
        my_put_str(elem[1]); my_put_char('\n');
        my_put_str(elem[2]); my_put_char('\n');
    }
}

void image_algo(char *str)
{
    char **tab = my_str_to_array(str, "\n");
    int i = set_i(tab); char **elem; print_first(tab, i);
    if (tab[i][0] == '#') {
        my_put_str(tab[i]); my_put_char('\n'); i++;
    }
    while (tab[i + 1] != NULL) {
        elem = my_str_to_array(tab[i], " ");
        if (elem[1] == NULL) {
            my_put_str(elem[0]); my_put_char('\n');
        } else {
            print_element(elem);
        }
        my_free_array(elem); i++;
    }
    my_free_array(tab);
}
