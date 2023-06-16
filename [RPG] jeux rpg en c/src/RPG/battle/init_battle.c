/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfRectangleShape *health_bar_init(int x, int y)
{
    sfRectangleShape *bar = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(bar, sfBlack);
    sfRectangleShape_setOutlineThickness(bar, 3.0);
    sfRectangleShape_setFillColor(bar, sfGreen);
    sfRectangleShape_setSize(bar, (sfVector2f){400, 50});
    sfRectangleShape_setPosition(bar, (sfVector2f){x, y});
    return (bar);
}

battle_t *battle_init(void)
{
    battle_t *battle = malloc(sizeof(battle_t));
    battle->bg =
        my_object_init("./assets/battle/bg.png;320;180;0;0;0;0;0;4;0");
    battle->buttons = button_list_init("./assets/battle/buttons.csv",
                (function_t[3]){fight_button, shield_button, item_button});
    battle->hp_player = health_bar_init(200, 200);
    battle->hp_ennemy = health_bar_init(1000, 200);
    battle->player = player_battle_init();
    battle->is_turn = sfFalse;
    return (battle);
}

void battle_start(game_t *G)
{
    my_object_place(G->battle->bg, G->win->center);
    sfRectangleShape_setPosition(G->battle->hp_ennemy,
        (sfVector2f){G->win->top_left.x + 825, G->win->top_left.y + 100});
    sfRectangleShape_setPosition(G->battle->hp_player,
        (sfVector2f){G->win->top_left.x + 50, G->win->top_left.y + 100});
    G->instance = BATTLE;
}

void battle_show(game_t *G)
{
    my_object_show(G->battle->bg, G->win);
    sfRenderWindow_drawRectangleShape(G->win->screen,
                            G->battle->hp_player, NULL);
    sfRenderWindow_drawRectangleShape(G->win->screen,
                            G->battle->hp_ennemy, NULL);
    my_object_show(G->battle->player->obj, G->win);
    my_object_animate(G->battle->player->obj);
    if (G->battle->is_turn == sfFalse) {
        button_list_show(G->battle->buttons, G->win);
        button_list_do_function(G, G->battle->buttons);
    }
}

void battle_destroy(battle_t *battle)
{
    my_object_destroy(battle->bg);
    button_list_destroy(battle->buttons);
    sfRectangleShape_destroy(battle->hp_ennemy);
    sfRectangleShape_destroy(battle->hp_player);
    player_battle_destroy(battle->player);
    free(battle);
}
