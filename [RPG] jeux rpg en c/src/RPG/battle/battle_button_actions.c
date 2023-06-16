/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void fight_button(game_t *G)
{
    G->battle->is_turn = sfTrue;
    my_object_change(&G->battle->player->obj,
                        G->battle->player->obj_list[1], 0);
    wait_animation_end(G, G->battle->player->obj, battle_show);
}

void shield_button(game_t *G)
{
    return;
}

void item_button(game_t *G)
{
    return;
}
