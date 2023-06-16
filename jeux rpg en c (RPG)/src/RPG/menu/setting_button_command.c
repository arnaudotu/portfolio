/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void plus_button(game_t *G)
{
    int vol = sfMusic_getVolume(G->bg_music);
    if (vol != 100) {
        sfMusic_setVolume(G->bg_music, vol + 10);
    }
}

void minus_button(game_t *G)
{
    int vol = sfMusic_getVolume(G->bg_music);
    if (vol != 0) {
        sfMusic_setVolume(G->bg_music, vol - 10);
    }
}

void back_button(game_t *G)
{
    G->instance = G->previous;
}

void enter_help(game_t *G)
{
    G->previous = G->instance;
    G->instance = HELP;
}
