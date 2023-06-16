/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../include/game.h"

void game_init_menues(game_t *G)
{
    G->title = menu_init("./assets/menu/title/obj.csv",
                        "./assets/menu/title/buttons.csv",
                        (function_t[4]){new_game, enter_settings, quit_game,
                            enter_help});
    G->pause = menu_init("./assets/menu/pause/obj.csv",
                        "./assets/menu/pause/buttons.csv",
                    (function_t[4]){enter_settings, quit_game, enter_help,
                        new_game});
    G->settings = menu_init("./assets/menu/gameover/obj.csv",
                        "./assets/menu/gameover/buttons.csv",
                        (function_t[4]){minus_button, plus_button,
                                    test_three, back_button});
    G->help = menu_init("./assets/menu/helper/obj.csv",
                        "./assets/menu/helper/buttons.csv",
                    (function_t[1]){back_button});
}

game_t *game_init(void)
{
    game_t *G = malloc(sizeof(game_t));
    G->player = player_init("./assets/player/player.csv");
    G->win = my_window_init((sfVector2f){1280, 720}, "RPG", 144);
    G->world_list = world_list_init("./assets/world/world_list.csv",
                    "./assets/world/tilemap_list.csv");
    set_all_world_functions(G->world_list);
    G->world = G->world_list[0];
    G->chat = dialogue_init();
    G->in_battle = sfFalse; G->in_chat = sfFalse; G->in_teleport = sfFalse;
    G->bubble =
        my_object_init("./assets/bubble.png;26;21;0;0;0;0;160;2;0");
    G->transition = transition_init();
    G->battle = battle_init();
    game_init_menues(G);
    my_camera_place(G->win, G->player->obj->pos);
    fix_camera(G, (sfVector2f){0, 0});
    init_music(G); G->instance = TITLE; return (G);
}

void game_destroy(game_t *G)
{
    player_destroy(G->player);
    world_list_destroy(G->world_list);
    my_window_destroy(G->win);
    my_object_destroy(G->bubble);
    dialogue_destroy(G->chat);
    sfRectangleShape_destroy(G->transition);
    destroy_music(G);
    menu_destroy(G->title);
    menu_destroy(G->pause);
    menu_destroy(G->settings);
    menu_destroy(G->help);
    battle_destroy(G->battle);
    free(G);
}

int main (int ac, char **av)
{
    game_t *G = game_init();
    object_t *splash =
        my_object_init("./assets/splash.png;320;180;800;400;58;32;160;4;0");
    my_object_place(splash, G->win->center);
    my_object_show(splash, G->win);
    my_window_refresh(G->win);
    my_time_wait(G->win, 3.0);
    my_object_destroy(splash);
    while (sfRenderWindow_isOpen(G->win->screen)) {
        sfRenderWindow_clear(G->win->screen, sfTransparent);
        manage_game_instances(G);
        my_window_refresh(G->win);
        fix_camera(G, (sfVector2f){0, 0});
    }
    game_destroy(G); return (0);
}
