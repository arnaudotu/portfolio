/*
** EPITECH PROJECT, 2022
** opperation3.c
** File description:
** douhiud
*/

#include "../include/my.h"
#include "../include/struct.h"

void rra_opperation(list_t *list)
{
    int c = list->l_a[list->size_la - 1];
    decale_a_right(list);
    list->l_a[0] = c;
    my_putstr("rra");
}

void rrb_opperation(list_t *list)
{
    int x = list->l_b[list->size_lb - 1];
    decale_b_right(list);
    list->l_b[0] = x;
    my_putstr("rrb");
}

void rrr_opperation(list_t *list)
{
    int c = list->l_a[list->size_la - 1];
    decale_a_right(list);
    list->l_a[0] = c;
    int x = list->l_b[list->size_lb - 1];
    decale_b_right(list);
    list->l_b[0] = x;
    my_putstr("rrr");
}
