/*
** EPITECH PROJECT, 2022
** my_csfml_sprite_movement.c
** File description:
** structure and functions of sprites
*/

#include "../../include/my_csfml.h"

object_t **my_object_list_init(char *filepath)
{
    char **tab = my_str_to_array(my_file_to_str(filepath), "\n\t ");
    object_t **object_list = malloc(sizeof(object_t) * (my_arraylen(tab) + 1));
    for (int i = 0; i < my_arraylen(tab); i++) {
        object_list[i] = my_object_init(tab[i]);
    }
    object_list[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (object_list);
}

void my_object_list_show(object_t **object_list, window_t *window)
{
    for (int i = 0; object_list[i] != NULL; i++) {
        my_object_show(object_list[i], window);
    }
}

void my_object_list_destroy(object_t **object_list)
{
    for (int i = 0; object_list[i] != NULL; i++) {
        my_object_destroy(object_list[i]);
    }
    free(object_list);
}
