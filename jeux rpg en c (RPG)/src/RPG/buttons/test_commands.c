/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void test_one(game_t *G)
{
    if (G->win->size.x == 1920 && G->win->size.y == 1080) {
        return;
    }
    my_window_change_res(G->win, 1920, 1080);
    my_putstr("Button 1 pressed!\n");
}

void test_two(game_t *G)
{
    if (G->win->size.x == 1280 && G->win->size.y == 720) {
        return;
    }
    my_window_change_res(G->win, 1280, 720);
    my_putstr("Button 2 pressed!\n");
}

void test_three(game_t *G)
{
    if (G->win->size.x == 1920 && G->win->size.y == 1080) {
        my_window_change_res(G->win, 1280, 720);
        return;
    }
    if (G->win->size.x == 1280 && G->win->size.y == 720) {
        my_window_change_res(G->win, 1920, 1080);
        return;
    }
}
