/*
** EPITECH PROJECT, 2022
** all_fonctions.c
** File description:
** arnaud
*/

#include "../include/my.h"
#include "../include/struct.h"

void sa_opperation(list_t *list)
{
    if (list->size_la > 0){
        int n = list->l_a[1];
        list->l_a[1] = list->l_a[0];
        list->l_a[0] = n;
        my_putstr("sa");
    }
}

void sb_opperation(list_t *list)
{
    if (list->size_lb > 0){
        int f = list->l_b[0];
        list->l_b[0] = list->l_b[1];
        list->l_b[1] = f;
        my_putstr("sb");
    }
}

void sc_opperation(list_t *list)
{
    if (list->size_la > 0 && list->size_lb > 0){
        int o = list->l_a[1];
        int m = list->l_b[1];
        list->l_a[1] = list->l_a[0];
        list->l_a[0] = o;
        list->l_b[1] = list->l_b[0];
        list->l_b[0] = m;
        my_putstr("sc");
    }
}

void pa_opperation(list_t *list)
{
    if (list->size_lb > 0){
        decale_a_right(list);
        list->size_la = list->size_la + 1;
        list->l_a[0] = list->l_b[0];
        decale_b_left(list);
        list->size_lb = list->size_lb - 1;
        my_putstr("pa");
    }
}

void pb_opperation(list_t *list)
{
    if (list->size_la > 0){
        decale_b_right(list);
        list->size_lb = list->size_lb + 1;
        list->l_b[0] = list->l_a[0];
        decale_a_left(list);
        list->size_la = list->size_la - 1;
        my_putstr("pb");
    }
}
