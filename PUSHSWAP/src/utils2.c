/*
** EPITECH PROJECT, 2022
** utils2.c
** File description:
** ez_fhreffr
*/

#include "../include/my.h"
#include "../include/struct.h"

int algo_court(list_t *list)
{
    if (list->l_a[0] < list->l_a[list->size_la - 1])
        rra_opperation(list);
        print_space(list);
    if (list->l_a[0] > list->l_a[list->size_la - 1])
        ra_opperation(list);
        print_space(list);
    if (list->l_a[0] > list->l_a[1])
        sa_opperation(list);
        print_space(list);
}

int print_space(list_t *list)
{
    if ((!is_sorted(list)))
        my_putstr(" ");
}
