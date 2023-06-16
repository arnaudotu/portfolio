/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfRectangleShape *transition_init(void)
{
    sfRectangleShape *transition = sfRectangleShape_create();
    sfRectangleShape_setFillColor(transition, sfTransparent);
    sfRectangleShape_setSize(transition, (sfVector2f){1280, 720});
    return (transition);
}

void transition_fade_in(game_t *G)
{
    sfColor color = sfRectangleShape_getFillColor(G->transition);
    if (color.a >= 255 || !sfRenderWindow_isOpen(G->win->screen)) {
        return;
    }
    sfRectangleShape_setPosition(G->transition, G->win->top_left);
    sfRenderWindow_clear(G->win->screen, sfTransparent);
    world_show(G, G->world);
    color.a += 5;
    sfRectangleShape_setFillColor(G->transition, color);
    sfRenderWindow_drawRectangleShape(G->win->screen,
                                G->transition, NULL);
    my_window_refresh(G->win);
    transition_fade_in(G);
}

void transition_fade_out(game_t *G)
{
    sfColor color = sfRectangleShape_getFillColor(G->transition);
    if (color.a <= 0 || !sfRenderWindow_isOpen(G->win->screen)) {
        return;
    }
    sfRectangleShape_setPosition(G->transition, G->win->top_left);
    sfRenderWindow_clear(G->win->screen, sfTransparent);
    world_show(G, G->world);
    player_movement(G);
    player_animation(G);
    color.a -= 5;
    sfRectangleShape_setFillColor(G->transition, color);
    sfRenderWindow_drawRectangleShape(G->win->screen,
                                G->transition, NULL);
    my_window_refresh(G->win);
    transition_fade_out(G);
}

void transition_fade_in_menu(game_t *G, menu_t *menu)
{
    sfColor color = sfRectangleShape_getFillColor(G->transition);
    if (color.a >= 255 || !sfRenderWindow_isOpen(G->win->screen)) {
        return;
    }
    sfRectangleShape_setPosition(G->transition, G->win->top_left);
    sfRenderWindow_clear(G->win->screen, sfTransparent);
    my_object_list_show(menu->obj_list, G->win);
    button_list_show(menu->button_list, G->win);
    color.a += 5;
    sfRectangleShape_setFillColor(G->transition, color);
    sfRenderWindow_drawRectangleShape(G->win->screen,
                                G->transition, NULL);
    my_window_refresh(G->win);
    transition_fade_in(G);
}

void transition_fade_out_menu(game_t *G, menu_t *menu)
{
    sfColor color = sfRectangleShape_getFillColor(G->transition);
    if (color.a <= 0 || !sfRenderWindow_isOpen(G->win->screen)) {
        return;
    }
    sfRectangleShape_setPosition(G->transition, G->win->top_left);
    sfRenderWindow_clear(G->win->screen, sfTransparent);
    my_object_list_show(menu->obj_list, G->win);
    button_list_show(menu->button_list, G->win);
    world_show(G, G->world);
    player_movement(G);
    player_animation(G);
    color.a -= 5;
    sfRectangleShape_setFillColor(G->transition, color);
    sfRenderWindow_drawRectangleShape(G->win->screen,
                                G->transition, NULL);
    my_window_refresh(G->win);
    transition_fade_out(G);
}
