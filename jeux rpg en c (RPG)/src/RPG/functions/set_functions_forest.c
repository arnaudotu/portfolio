/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void set_function_forest_1(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/forest_1/all_dialogue.csv");
    world->npc_fct[1] = dissapear;
}

void set_function_forest_2(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/forest_2/all_dialogue.csv");
}

void set_function_forest_3(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/forest_3/all_dialogue.csv");
}

void set_function_forest_4(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/forest_4/all_dialogue.csv");
}

void set_function_forest_5(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/forest_5/all_dialogue.csv");
}
