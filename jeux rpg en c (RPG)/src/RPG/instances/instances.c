/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void show_setting(game_t *G)
{
    menu_show(G, G->settings);
}

void show_game(game_t *G)
{
    player_animation(G);
    player_movement(G);
    world_show(G, G->world);
    if (check_menu_input(G)) {
        G->instance = PAUSE;
        G->previous = GAME;
    }
}

void manage_game_instances(game_t *G)
{
    switch (G->instance) {
        case TITLE: menu_show(G, G->title); break;
        case GAME: show_game(G); break;
        case BATTLE: battle_show(G); break;
        case GAME_OVER: show_game(G); break;
        case PAUSE: menu_show(G, G->pause); break;
        case SETTINGS: show_setting(G); break;
        case HELP: menu_show(G, G->help); break;
        case END: show_game(G); break;
    };
}
