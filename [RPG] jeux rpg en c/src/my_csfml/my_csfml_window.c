/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** functions related to window
*/

#include "../../include/my_csfml.h"

window_t *my_window_init(sfVector2f size, char* name, int fps)
{
    window_t *window = malloc(sizeof(window_t));
    window->size = (sfVector2f){size.x, size.y};
    sfVideoMode mode = {size.x, size.y, 32};
    window->screen = sfRenderWindow_create(mode, name,
                        sfClose | sfTitlebar, NULL);
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfRenderWindow_setFramerateLimit(window->screen, fps);
    sfRenderWindow_setPosition(window->screen,
        (sfVector2i){desktop.width / 2 - size.x / 2,
        desktop.height / 2 - size.y / 2});
    my_camera_change_anchor_points(window);
    window->camera = my_camera_init(window);
    window->fps = fps;
    window->clock = sfClock_create();
    window->tpf = 0;
    sfRenderWindow_setKeyRepeatEnabled(window->screen, sfFalse);
    return (window);
}

void my_window_refresh(window_t *window)
{
    sfRenderWindow_display(window->screen);
    my_event_check(window);
    window->tpf = sfTime_asSeconds(sfClock_getElapsedTime(window->clock));
    sfClock_restart(window->clock);
}

void my_window_check_limit(window_t *window, int x, int y)
{
    if (window->size.x < 800 || window->size.y < 600) {
        sfRenderWindow_setSize(window->screen, (sfVector2u){x, y});
        my_camera_change_anchor_points(window);
        sfFloatRect area = {0, 0, x, y};
        sfRenderWindow_setView(window->screen, sfView_createFromRect(area));
    }
}

void my_window_change_res(window_t *window, int x, int y)
{
    if (x == window->size.x && y == window->size.y) {
        return;
    }
    sfRenderWindow_setSize(window->screen, (sfVector2u){x, y});
    sfVideoMode desktop = sfVideoMode_getDesktopMode();
    sfRenderWindow_setPosition(window->screen,
        (sfVector2i){desktop.width / 2 - x / 2, desktop.height / 2 - y / 2});
    my_camera_change_anchor_points(window);
    window->size.x = x; window->size.y = y;
    my_camera_place(window, window->center);
}

void my_window_destroy(window_t *window)
{
    sfRenderWindow_destroy(window->screen);
    sfClock_destroy(window->clock);
    sfView_destroy(window->camera);
    free(window);
}
