/*
** EPITECH PROJECT, 2022
** all_fonction2.c
** File description:
** uehujdez
*/

#include "../include/my.h"
#include "../include/struct.h"

void ra_opperation(list_t *list)
{
    int c = list->l_a[0];
    decale_a_left(list);
    list->l_a[list->size_la - 1] = c;
    my_putstr("ra");
}

void rb_opperation(list_t *list)
{
    int x = list->l_b[0];
    decale_b_left(list);
    list->l_b[list->size_lb - 1] = x;
    my_putstr("rb");
}

void rr_opperation(list_t *list)
{
    int c = list->l_a[0];
    decale_a_left(list);
    list->l_a[list->size_la - 1] = c;
    int x = list->l_b[0];
    decale_b_left(list);
    list->l_b[list->size_lb - 1] = x;
    my_putstr("rr");
}
