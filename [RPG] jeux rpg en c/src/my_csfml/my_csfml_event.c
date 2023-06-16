/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of events
*/

#include "../../include/my_csfml.h"

void my_event_close_window(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->screen);
}

void my_event_resize_window(window_t *window)
{
    if (window->event.type == sfEvtResized) {
        sfVector2u size = sfRenderWindow_getSize(window->screen);
        window->size.x = size.x; window->size.y = size.y;
        my_camera_change_anchor_points(window);
    }
}

void my_event_check(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->screen, &window->event)) {
        my_event_close_window(window);
        window->input = sfKeyUnknown;
        if (window->event.type == sfEvtKeyPressed) {
            window->input = window->event.key.code; break;
        } else {
            window->input = sfKeyUnknown; break;
        }
        if (window->event.type == sfEvtMouseButtonReleased) {
            window->input = sfMouseLeft;
        }
    }
}
