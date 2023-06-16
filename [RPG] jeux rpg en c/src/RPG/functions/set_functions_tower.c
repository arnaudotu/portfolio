/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void set_function_tower_1(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/tower_1/all_dialogue.csv");
}

void set_function_tower_2(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/tower_2/all_dialogue.csv");
}

void set_function_tower_3(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/tower_3/all_dialogue.csv");
}

void set_function_tower_4(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/tower_4/all_dialogue.csv");
}

void set_function_tower_5(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/tower_5/all_dialogue.csv");
}
