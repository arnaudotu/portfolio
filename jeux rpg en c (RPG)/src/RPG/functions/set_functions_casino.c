/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void set_function_casino_1(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/casino_1/all_dialogue.csv");
}

void set_function_casino_2(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/casino_2/all_dialogue.csv");
}

void set_function_casino_3(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/casino_3/all_dialogue.csv");
}

void set_function_casino_4(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/casino_4/all_dialogue.csv");
}

void set_function_casino_5(world_t *world)
{
    world->npc_fct = function_list_init();
    world->npc_speak =
        world_dialogue_init("./assets/dialogue/casino_5/all_dialogue.csv");
}
