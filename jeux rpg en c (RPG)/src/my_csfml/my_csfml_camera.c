/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** functions related to camera (you need a window)
*/

#include "../../include/my_csfml.h"

sfView *my_camera_init(window_t *window)
{
    sfView *new_camera = sfView_create();
    sfView_setCenter(new_camera, window->center);
    sfView_setSize(new_camera, window->size);
    sfRenderWindow_setView(window->screen, new_camera);
    return (new_camera);
}

void my_camera_change_anchor_points(window_t *window)
{
    sfVector2u size = sfRenderWindow_getSize(window->screen);
    window->top_left = sfRenderWindow_mapPixelToCoords(window->screen,
                (sfVector2i){0, 0}, window->camera);
    window->top_right = sfRenderWindow_mapPixelToCoords(window->screen,
                (sfVector2i){size.x, 0}, window->camera);
    window->center = sfRenderWindow_mapPixelToCoords(window->screen,
                (sfVector2i){size.x / 2, size.y / 2}, window->camera);
    window->bottom_left = sfRenderWindow_mapPixelToCoords(window->screen,
                (sfVector2i){0, size.y}, window->camera);
    window->bottom_right = sfRenderWindow_mapPixelToCoords(window->screen,
                (sfVector2i){size.x, size.y}, window->camera);
}

void my_camera_move(window_t *window, sfVector2f move)
{
    sfView_move(window->camera, move);
    sfRenderWindow_setView(window->screen, window->camera);
    my_camera_change_anchor_points(window);
}

void my_camera_place(window_t *window, sfVector2f pos)
{
    sfView_setCenter(window->camera, pos);
    sfRenderWindow_setView(window->screen, window->camera);
    my_camera_change_anchor_points(window);
}
