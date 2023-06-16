/*
** EPITECH PROJECT, 2022
** my_pushwap.c
** File description:
** hgfiufhre
*/

#include "../include/my.h"
#include "../include/struct.h"

int str_to_int(char *str)
{
    int i = 0;
    int neg = 1;
    int n = 0;
    if (str[0] == '-'){
        neg = -1;
        i++;
    }
    for (i; str[i] != '\0' && str[i] <= '9'; i++)
        n = n * 10 + (str[i] - '0');
    return (n * neg);
}

int check_list(list_t *list, int argc)
{
    while (list->l_a[list->size_la] > list->l_a[list->size_la - 1])
        list->size_la = list->size_la - 1;
    if (list->size_la == -1){
        my_putstr("\n");
        printf("%d", list->l_a);

        exit ;
    } else {
        list->size_la = argc - 1;
        algo(list);
    }
}

int main(int argc, char **argv)
{
    list_t *list = malloc(sizeof(*list));
    list->l_a = malloc(sizeof(int) * (argc - 1));
    list->l_b = malloc(sizeof(int) * (argc - 1));
    list->size_la = argc - 1; list->size_lb = 0;

    if (argc < 2){
        my_putstr("\n");
        return (0);
    }

    for (int e = 0; e < argc - 1; e++){
        list->l_a[e] = str_to_int(argv[e + 1]);
    }
    my_putstr("\n");
    my_putstr("operation :   ");
    if (argc >= 3){
        check_list(list, argc);
    }
    my_putstr("\n");
    my_putstr("result :   ");
    for (int i = 0; i < list->size_la; i++) {
        my_putnbr(list->l_a[i]);
        my_putstr(" ");
    }
    my_putstr("\n\n");
    free (list);
}
