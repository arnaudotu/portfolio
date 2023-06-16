/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of tilemaps
*/

#include "../../include/my_csfml.h"

tilemap_t **my_tilemap_list_init(char *filepath)
{
    char **tab = my_str_to_array(my_file_to_str(filepath), "\n\t ");
    tilemap_t **tilemap_list = malloc(sizeof(tilemap_t) * my_arraylen(tab));
    for (int i = 0; i < my_arraylen(tab); i++) {
        tilemap_list[i] = my_tilemap_init(tab[i]);
    }
    tilemap_list[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (tilemap_list);
}

void my_tilemap_list_show(tilemap_t **tilemap_list, window_t *window)
{
    for (int i = 0; tilemap_list[i] != NULL; i++) {
        my_tilemap_show(tilemap_list[i], window);
    }
}

void my_tilemap_change(tilemap_t **dest, tilemap_t *src)
{
    (*dest) = src;
}

void my_tilemap_list_destroy(tilemap_t **tilemap_list)
{
    for (int i = 0; tilemap_list[i] != NULL; i++) {
        my_tilemap_destroy(tilemap_list[i]);
    }
    free(tilemap_list);
}
