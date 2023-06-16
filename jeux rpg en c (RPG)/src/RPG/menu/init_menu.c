/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

menu_t *menu_init(char *bg_info, char *button_file, function_t *functions)
{
    menu_t *menu = malloc(sizeof(menu_t));
    menu->obj_list = my_object_list_init(bg_info);
    menu->button_list = button_list_init(button_file, functions);
    return (menu);
}

void menu_show(game_t *G, menu_t *menu)
{
    for (int i = 0; menu->obj_list[i] != NULL; i++) {
        my_object_place(menu->obj_list[i], G->win->center);
    }
    my_object_list_show(menu->obj_list, G->win);
    my_object_list_show(menu->obj_list, G->win);
    button_list_show(menu->button_list, G->win);
    button_list_do_function(G, menu->button_list);
    my_object_list_animate(menu->obj_list);
}

void menu_destroy(menu_t *menu)
{
    my_object_list_destroy(menu->obj_list);
    button_list_destroy(menu->button_list);
    free(menu);
}
