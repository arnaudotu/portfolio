/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void player_animation(game_t *G)
{
    if (!check_arrow_input()) {
        my_object_set_frame(G->player->obj, 1);
        my_object_change(&G->player->obj, G->player->obj_list[0], 1);
        return;
    }
    if (check_run_input()) {
        my_object_change(&G->player->obj, G->player->obj_list[1], 1);
    } else {
        my_object_change(&G->player->obj, G->player->obj_list[0], 1);
    }
    if (check_left_input())
        my_object_set_anim(G->player->obj, 1);
    if (check_right_input())
        my_object_set_anim(G->player->obj, 2);
    if (check_up_input())
        my_object_set_anim(G->player->obj, 3);
    if (check_down_input())
        my_object_set_anim(G->player->obj, 0);
    my_object_animate(G->player->obj);
}
