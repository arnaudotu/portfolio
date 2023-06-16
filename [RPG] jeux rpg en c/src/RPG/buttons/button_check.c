/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void button_list_set_states(button_t **button_list, window_t *win)
{
    for (int i = 0; button_list[i] != NULL; i++) {
        button_set_states(button_list[i], win);
    }
}

void button_list_do_function(game_t *G, button_t **button_list)
{
    for (int i = 0; button_list[i] != NULL; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft)
            && button_list[i]->state == PRESSED) {
            button_list[i]->function (G);
        }
    }
}

void button_set_states(button_t *button, window_t *win)
{
    if (button->state == OFF) {
        my_object_set_frame(button->obj, button->state);
        return;
    }
    if (my_mouse_in_object(win, button->obj)) {
        button->state = HOVER;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->state = PRESSED;
        }
        my_object_set_frame(button->obj, button->state);
        return;
    }
    my_object_set_frame(button->obj, button->state);
    button->state = ACTIVE;
}
