/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfBool my_camera_in_tilemap(window_t *win, tilemap_t *tilemap, sfVector2f move)
{
    sfFloatRect h_cam;
    sfVector2f size = sfView_getSize(win->camera);
    sfFloatRect h_map = tilemap->hitbox;
    h_cam.left = win->top_left.x + move.x;
    h_cam.width = size.x;
    h_cam.top = win->top_left.y + move.y;
    h_cam.height = size.y;
    if (h_cam.left >= h_map.left
        && h_cam.top >= h_map.top
        && h_cam.left + h_cam.width <= h_map.width
        && h_cam.top + h_cam.height <= h_map.height) {
            return (1);
    }
    return (0);
}

void fix_camera(game_t *G, sfVector2f move)
{
    if (my_camera_in_tilemap(G->win, G->world->map, move)) {
        return;
    }
    sfVector2f repos = sfView_getCenter(G->win->camera);
    sfVector2f cam_size = sfView_getSize(G->win->camera);
    int tilesize = G->world->map->tile_size;
    if (G->win->top_left.x < 0)
        repos.x = cam_size.x / 2;
    if (G->win->top_left.y < 0)
        repos.y = cam_size.y / 2;
    if (G->win->bottom_right.x > G->world->map->size.x * tilesize)
        repos.x = (G->world->map->size.x * tilesize) - (cam_size.x / 2);
    if (G->win->bottom_right.y > G->world->map->size.y * tilesize)
        repos.y = (G->world->map->size.y * tilesize) - (cam_size.y / 2);
    my_camera_place(G->win, repos);
}

void camera_movement(game_t *G, sfVector2f move)
{
    sfVector2f horizontal = {move.x, 0};
    sfVector2f vertical = {0, move.y};
    if (move.x < 0 && G->player->obj->pos.x < G->win->center.x) {
        my_camera_move(G->win, horizontal); fix_camera(G, horizontal);
    }
    if (move.x > 0 && G->player->obj->pos.x > G->win->center.x) {
        my_camera_move(G->win, horizontal); fix_camera(G, horizontal);
    }
    if (move.y < 0 && G->player->obj->pos.y < G->win->center.y) {
        my_camera_move(G->win, vertical); fix_camera(G, vertical);
    }
    if (move.y > 0 && G->player->obj->pos.y > G->win->center.y) {
        my_camera_move(G->win, vertical); fix_camera(G, vertical);
    }
}
