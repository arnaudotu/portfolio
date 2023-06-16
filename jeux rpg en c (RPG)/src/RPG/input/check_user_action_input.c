/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfBool check_run_input(void)
{
    if (!sfKeyboard_isKeyPressed(sfKeyLShift)) {
            return (sfFalse);
    }
    return (sfTrue);
}

sfBool check_confirm_input(game_t *G)
{
    if (G->win->input == sfKeySpace) {
        G->win->input = sfKeyUnknown;
        return (sfTrue);
    }
    return (sfFalse);
}

sfBool check_cancel_input(game_t *G)
{
    if (G->win->input == sfKeyX) {
        return (sfTrue);
    }
    return (sfFalse);
}

sfBool check_menu_input(game_t *G)
{
    if (G->win->input == sfKeyEscape) {
        return (sfTrue);
    }
    return (sfFalse);
}
