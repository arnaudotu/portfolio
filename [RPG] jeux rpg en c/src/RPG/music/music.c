/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#include "../../../include/game.h"

void init_music(game_t *G)
{
    G->bg_music = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setVolume(G->bg_music, 15);
    sfMusic_setLoop(G->bg_music, sfTrue);
    sfMusic_play(G->bg_music);
}

void destroy_music(game_t *G)
{
    sfMusic_stop(G->bg_music);
    sfMusic_destroy(G->bg_music);
}
