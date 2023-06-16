/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

playerbattle_t *player_battle_init(void)
{
    playerbattle_t *player = malloc(sizeof(playerbattle_t));
    player->obj_list =
            my_object_list_init("./assets/battle/player_battle_objects.csv");
    player->obj = player->obj_list[0];
    return (player);
}

void player_battle_destroy(playerbattle_t *player)
{
    my_object_list_destroy(player->obj_list);
    free(player);
}
