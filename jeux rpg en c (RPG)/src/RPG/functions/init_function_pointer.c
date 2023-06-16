/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

int *npc_switch_init(world_t *world)
{
    int *npc_switch = malloc(sizeof(int) * 30);
    for (int i = 0; i < 30; i++) {
        npc_switch[i] = 0;
    }
    return (npc_switch);
}

function_t *function_list_init(void)
{
    function_t *function_list = malloc(sizeof(function_t) * 30);
    for (int i = 0; i < 30; i++) {
        function_list[i] = NULL;
    }
    return (function_list);
}

void dissapear(game_t *G)
{
    G->world->npc_switch[1] = 1;
}

void set_all_world_functions(world_t **world)
{
    void (*function[20])(world_t *world) =
        {set_function_forest_1, set_function_forest_2,
        set_function_forest_5, set_function_desert_1,
        set_function_desert_2, set_function_desert_3};
    int size = 0;
    for (int i = 0; world[i] != NULL; i++) {
        size++;
    }
    for (int i = 0; i < size; i++) {
        function[i] (world[i]);
        world[i]->npc_switch = npc_switch_init(world[i]);
    }
}
