/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void new_game(game_t *G)
{
    G->instance = GAME;
}

void enter_settings(game_t *G)
{
    G->previous = G->instance;
    G->instance = SETTINGS;
}

void quit_game(game_t *G)
{
    sfRenderWindow_close(G->win->screen);
}
