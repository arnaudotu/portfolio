/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfBool player_in_tilemap(game_t *G, sfVector2f move)
{
    sfFloatRect h_plyr = G->player->obj->hitbox;
    sfFloatRect h_map = G->world->map->hitbox;
    h_plyr.left += move.x;
    h_plyr.top += move.y;
    if (h_plyr.left >= h_map.left
        && h_plyr.top >= h_map.top
        && h_plyr.left + h_plyr.width <= h_map.width
        && h_plyr.top + h_plyr.height <= h_map.height) {
            return (1);
    }
    return (0);
}

sfVector2f get_player_movement(float move_speed)
{
    sfVector2f movement = {0, 0};
    if (check_up_input())
        movement.y -= move_speed;
    if (check_down_input())
        movement.y += move_speed;
    if (check_left_input())
        movement.x -= move_speed;
    if (check_right_input())
        movement.x += move_speed;
    return (movement);
}

int movement_next_pos(float move)
{
    if (move == 0) {
        return (0);
    }
    if (move > 0) {
        return (1);
    }
    return (-1);
}

sfBool player_touch_wall(game_t *G, sfVector2f move)
{
    sfVector2i obj_pos = {G->player->obj->pos.x, G->player->obj->pos.y};
    move.x = movement_next_pos(move.x); move.y = movement_next_pos(move.y);
    int tile_s = G->world->map->tile_size;
    sfVector2i h_size = {((G->player->obj->hitbox.width / 2)),
                            ((G->player->obj->hitbox.height / 2))};
    obj_pos.y += h_size.y + (10 * move.y);
    if (move.y == 0) {
        obj_pos.x += (move.x * (h_size.x + 5));
        int tile = G->world->map->map_walls[(obj_pos.x / tile_s) +
                        ((obj_pos.y / tile_s) * (int)G->world->map->size.x)];
        return (tile);
    }
    obj_pos.x += (move.y * (h_size.x));
    int tile1 = G->world->map->map_walls[(obj_pos.x / tile_s) +
                    ((obj_pos.y / tile_s) * (int)G->world->map->size.x)];
    obj_pos.x -= (move.y * (h_size.x)) * 2;
    int tile2 = G->world->map->map_walls[(obj_pos.x / tile_s) +
                    ((obj_pos.y / tile_s) * (int)G->world->map->size.x)];
    return (tile1 || tile2);
}

void player_movement(game_t *G)
{
    if (!check_arrow_input()) {
        return;
    } float move_speed = G->player->mv_spd * G->win->tpf;
    if (check_run_input()) {
        move_speed = G->player->run_spd * G->win->tpf;
    } sfVector2f move = get_player_movement(move_speed);
    sfVector2f horizontal = {move.x, 0}; sfVector2f vertical = {0, move.y};
    if (player_in_tilemap(G, horizontal)
        && !player_touch_wall(G, horizontal)
        && !player_touch_world(G, horizontal)) {
        my_object_move(G->player->obj, horizontal);
        camera_movement(G, horizontal);
    }
    if (player_in_tilemap(G, vertical)
        && !player_touch_wall(G, vertical)
        && !player_touch_world(G, vertical)) {
        my_object_move(G->player->obj, vertical);
        camera_movement(G, vertical);
    }
}
