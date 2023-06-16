/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of tilemaps
*/

#include "../../include/my_csfml.h"

int *my_get_tilemap_layout(char *file)
{
    char *str = my_file_to_str(file);
    char **tab = my_str_to_array(str, "\n ,;");
    int *layout =
        malloc(sizeof(int) * my_strlen(tab[0]) * my_arraylen(tab) + 1);
    for (int i = 0; tab[i] != NULL; i++) {
        layout[i] = my_str_to_int(tab[i]);
    }
    my_free_array(tab); free(str);
    return (layout);
}

void my_tilemap_fill(tilemap_t *tilemap)
{
    sfVertexArray_resize(tilemap->map, tilemap->size.x * tilemap->size.y * 4);
    sfVertex *tile; int t_x; int t_y; int tile_nbr;
    int t_s = tilemap->tile_size; int width = tilemap->size.x;
    int texture_size = sfTexture_getSize(tilemap->states.texture).x;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < tilemap->size.y; j++) {
            tile_nbr = tilemap->map_layout[i + j * width] - 1;
            t_x = tile_nbr % (texture_size / t_s);
            t_y = tile_nbr / (texture_size / t_s);
            tile = sfVertexArray_getVertex(tilemap->map, (i + j * width) * 4);
            tile[0].position = (sfVector2f){i * t_s, j * t_s};
            tile[1].position = (sfVector2f){(i + 1) * t_s, j * t_s};
            tile[2].position = (sfVector2f){(i + 1) * t_s, (j + 1) * t_s};
            tile[3].position = (sfVector2f){i * t_s, (j + 1) * t_s};
            tile[0].texCoords = (sfVector2f){t_x * t_s, t_y * t_s};
            tile[1].texCoords = (sfVector2f){(t_x + 1) * t_s, t_y * t_s};
            tile[2].texCoords = (sfVector2f){(t_x + 1) * t_s, (t_y + 1) * t_s};
            tile[3].texCoords = (sfVector2f){t_x * t_s, (t_y + 1) * t_s};
        }
    }
}

tilemap_t *my_tilemap_init(char *info)
{
    char **tab = my_str_to_array(info, ";");
    tilemap_t *tilemap = malloc(sizeof(tilemap_t));
    tilemap->map_layout = my_get_tilemap_layout(tab[1]);
    tilemap->map_walls = my_get_tilemap_layout(tab[2]);
    tilemap->map = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(tilemap->map, sfQuads);
    tilemap->states.shader = NULL;
    tilemap->states.texture = sfTexture_createFromFile(tab[0], NULL);
    tilemap->states.transform = sfTransform_Identity;
    tilemap->states.blendMode = sfBlendAlpha;
    tilemap->size = (sfVector2f){my_str_to_int(tab[3]), my_str_to_int(tab[4])};
    tilemap->pos = (sfVector2f){0, 0};
    tilemap->tile_size = my_str_to_int(tab[5]);
    my_tilemap_fill(tilemap);
    sfTransform_translate(&tilemap->states.transform,
                            tilemap->pos.x, tilemap->pos.y);
    tilemap->hitbox = sfVertexArray_getBounds(tilemap->map);
    my_free_array(tab);
    return (tilemap);
}

void my_tilemap_show(tilemap_t *tilemap, window_t *window)
{
    sfRenderWindow_drawVertexArray(window->screen,
            tilemap->map, &tilemap->states);
}

void my_tilemap_destroy(tilemap_t *tilemap)
{
    sfVertexArray_destroy(tilemap->map);
    free(tilemap->map_layout);
    free(tilemap->map_walls);
    free(tilemap);
}
