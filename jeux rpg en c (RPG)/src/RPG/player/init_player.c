/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

player_t *player_init(char *object_info_list)
{
    player_t *player = malloc(sizeof(player_t));
    player->obj_list = my_object_list_init(object_info_list);
    player->obj = player->obj_list[0];
    player->mv_spd = 250; player->run_spd = 450;
    return (player);
}

void player_destroy(player_t *player)
{
    my_object_list_destroy(player->obj_list);
    free(player);
}
