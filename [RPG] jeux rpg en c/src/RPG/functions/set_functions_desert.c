/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void set_function_desert_1(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/desert_1/all_dialogue.csv");
}

void set_function_desert_2(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/desert_2/all_dialogue.csv");
}

void set_function_desert_3(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/desert_3/all_dialogue.csv");
}

void set_function_desert_4(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/desert_4/all_dialogue.csv");
}

void set_function_desert_5(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/desert_5/all_dialogue.csv");
}
