/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

button_t *button_init(char *object_info, function_t function)
{
    button_t *button = malloc(sizeof(button_t));
    button->obj = my_object_init(object_info);
    button->state = ACTIVE;
    button->pos_show = button->obj->pos;
    button->function = function;
    return (button);
}

button_t **button_list_init(char *filepath, function_t *functions)
{
    char **tab = my_str_to_array(my_file_to_str(filepath), "\n\t ");
    button_t **button_list = malloc(sizeof(button_t) * my_arraylen(tab));
    for (int i = 0; i < my_arraylen(tab); i++) {
        button_list[i] = button_init(tab[i], functions[i]);
    }
    button_list[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (button_list);
}

void button_destroy(button_t *button)
{
    my_object_destroy(button->obj);
    free(button);
}

void button_list_show(button_t **button_list, window_t *win)
{
    sfVector2f pos = {0, 0};
    for (int i = 0; button_list[i] != NULL; i++) {
        pos.x = win->top_left.x + button_list[i]->pos_show.x;
        pos.y = win->top_left.y + button_list[i]->pos_show.y;
        my_object_place(button_list[i]->obj, pos);
        my_object_show(button_list[i]->obj, win);
        button_set_states(button_list[i], win);
    }
}

void button_list_destroy(button_t **button_list)
{
    for (int i = 0; button_list[i] != NULL; i++) {
        button_destroy(button_list[i]);
    }
    free(button_list);
}
