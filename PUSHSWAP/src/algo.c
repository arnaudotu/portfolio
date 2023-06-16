/*
** EPITECH PROJECT, 2022
** algo.c
** File description:
** uyfi
*/

#include "../include/my.h"
#include "../include/struct.h"

void *algo(list_t *list)
{
    while (!is_sorted(list)) {
        suite_algo1(list);
        suite_algo2(list);
    }
    my_putstr("\n");
}

int list_sorted(list_t *list)
{
    const int true = 1;
    const int false = 0;
    int i;

    for (i = 1; i < (list->size_la); i++){
        if (list->l_a[i - 1] <= list->l_a[i]){
            continue;
        } else {
            return (false);
        }
    }
    return (true);
}

void check_b(list_t *list)
{
    if (list->size_lb >= 2) {
        if (list->l_b[0] < list->l_b[list->size_lb]){
            rb_opperation(list);
            print_space(list);
        }
        if (list->l_b[0] < list->l_b[1]){
            sb_opperation(list);
            print_space(list);
        }
    }
}

void *suite_algo1(list_t *list)
{
    if (list->l_a[0] > list->l_a[list->size_la - 1]){
        ra_opperation(list);
        print_space(list);
    }
    if (list->l_a[0] > list->l_a[1]){
        sa_opperation(list);
        print_space(list);
    }
    list->check_sorted_la = list_sorted(list);
    if (list->check_sorted_la == 0 &&
        (list->l_a[0] <= list->l_a[1])) {
        pb_opperation(list);
        print_space(list);
        check_b(list);
    }
}

void *suite_algo2(list_t *list)
{
    if (list->check_sorted_la == 1){
	    if (list->check_sorted_la == 1 && list->l_b[0] == 0){
            exit ;
        }
        pa_opperation(list);
        print_space(list);
        list->check_sorted_la = list_sorted(list);
    }
}
