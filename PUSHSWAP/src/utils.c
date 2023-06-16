/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** oihfeiyzoif
*/

#include "../include/my.h"
#include "../include/struct.h"

int decale_a_left(list_t *list)
{
    for (int e = 1; e < list->size_la; e++)
        list->l_a[e - 1] = list->l_a[e];
}

int decale_b_right(list_t *list)
{
    for (int e = list->size_lb - 1; e >= 0; e--)
        list->l_b[e + 1] = list->l_b[e];
}

int decale_a_right(list_t *list)
{
    for (int e = list->size_la - 1; e >= 0; e--)
        list->l_a[e + 1] = list->l_a[e];
}

int decale_b_left(list_t *list)
{
    for (int e = 1; e < list->size_lb; e++)
        list->l_b[e - 1] = list->l_b[e];
}

int is_sorted(list_t *list)
{
    if (list->size_lb != 0)
        return (0);
    for (int i = 1; i < list->size_la; i++){
        if (list->l_a[i] < list->l_a[i - 1])
            return (0);
    }
    return (1);
}
