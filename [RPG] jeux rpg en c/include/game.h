/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** header of the game functions
*/

#include "my_csfml.h"
#include <math.h>
#include <stdio.h>

//========================ENUM==================================

typedef enum boss {
    CATAPILA = 0,
    JIMMY = 1,
    GRINDER = 2,
    FINAL_CATAPILA = 3,
    MARVIN = 4
} boss;

typedef enum ennemy {
    RANDOM = -1,
} ennemy;

typedef enum game_instance {
    TITLE = 0,
    GAME = 1,
    BATTLE = 2,
    GAME_OVER = 3,
    PAUSE = 4,
    END = 5,
    SETTINGS = 6,
    HELP = 7,
} game_instance;

typedef enum item_type {
    HEAL = 0,
    ATK_BOOST = 1,
    DEF_BOOST = 2
} item_type;

typedef enum attack_type {
    PHYSIC = 0,
    MAGIC = 1,
    SHIELD = 2,
    BOOST = 3
} attack_type;

typedef enum button_state {
    ACTIVE = 0,
    HOVER = 1,
    PRESSED = 2,
    OFF = 3
} button_state;

//=======================STRUCTS=================================

typedef struct item_t {
    char *name;
    object_t *obj;
    item_type type;
    int value_type;
} item_t;

typedef struct game_t game_t;
typedef void (*function_t) (game_t *G);

typedef struct button_t {
    object_t *obj;
    button_state state;
    function_t function;
    sfVector2f pos_show;
} button_t;

typedef struct attack_t {
    char *name;
    int base_dmg;
    attack_type type;
} attack_t;

typedef struct ennemy_t {
    char *name;
    object_t *obj;
    int hp;
    int atk;
    int def;
    attack_type weak;
} ennemy_t;

typedef struct playerbattle_t {
    object_t **obj_list;
    object_t *obj;
} playerbattle_t;

typedef struct battle_t {
    object_t *bg;
    playerbattle_t *player;
    ennemy_t *ennemy;
    sfRectangleShape *hp_player;
    sfRectangleShape *hp_ennemy;
    button_t **buttons;
    sfBool is_turn;
} battle_t;

typedef struct player_t {
    object_t **obj_list;
    object_t *obj;
    float mv_spd;
    float run_spd;
    sfBool can_move;
    int hp;
    int atk;
    int def;
    int lvl;
    int exp;
    item_t **inventory;
} player_t;


typedef struct menu_t {
    object_t **obj_list;
    button_t **button_list;
} menu_t;

typedef struct speak_t {
    char *name;
    int face_id;
    int face_frame;
    char *content;
} speak_t;

typedef struct teleport_t {
    sfFloatRect zone;
    sfVector2f tp_pos;
    int world_id;
} teleport_t;

typedef struct world_t {
    tilemap_t *map;
    object_t **bg_list;
    object_t **npc_list;
    speak_t ***npc_speak;
    teleport_t **tp_list;
    sfBool battle;
    function_t *npc_fct;
    int *npc_switch;
    int current_npc;
} world_t;

typedef struct dialogue_t {
    object_t **obj_list;
    text_t *name;
    text_t *text;
    int line;
} dialogue_t;

typedef struct game_t {
    char **save_data;
    battle_t *battle;
    sfRectangleShape *transition;
    sfBool in_chat;
    sfBool in_battle;
    sfBool in_teleport;
    game_instance instance;
    game_instance previous;
    window_t *win;
    player_t *player;
    object_t *bubble;
    dialogue_t *chat;
    menu_t *title;
    menu_t *help;
    menu_t *settings;
    menu_t *pause;
    world_t **world_list;
    world_t *world;
    item_t **item_list;
    ennemy_t **ennemies;
    ennemy_t **bosses;
    audio_t **bmg;
    sfMusic *bg_music;
    audio_t **music;
} game_t;

#ifndef GAME_H_
    #define GAME_H_

    player_t *player_init(char *object_info_list);
    void player_destroy(player_t *player);

    void manage_game_instances(game_t *G);

    sfBool check_arrow_input(void);
    sfBool check_left_input(void);
    sfBool check_right_input(void);
    sfBool check_up_input(void);
    sfBool check_down_input(void);
    sfBool check_run_input(void);
    sfBool check_confirm_input(game_t *G);
    sfBool check_cancel_input(game_t *G);
    sfBool check_menu_input(game_t *G);

    void camera_movement(game_t *G, sfVector2f move);
    void fix_camera(game_t *G, sfVector2f move);

    void player_movement(game_t *G);
    void player_animation(game_t *G);

    button_t *button_init(char *object_info, function_t function);
    button_t **button_list_init(char *filepath, function_t *functions);
    void button_destroy(button_t *button);
    void button_list_show(button_t **button_list, window_t *win);
    void button_list_destroy(button_t **button_list);
    void button_list_set_states(button_t **button_list, window_t *win);
    void button_list_do_function(game_t *G, button_t **button_list);
    void button_set_states(button_t *button, window_t *win);

    void test_one(game_t *G);
    void test_two(game_t *G);
    void test_three(game_t *G);
    void plus_button(game_t *G);
    void minus_button(game_t *G);
    void enter_settings(game_t *G);
    void back_button(game_t *G);
    void dissapear(game_t *G);

    world_t *world_init(char *info, char *tilemap);
    world_t **world_list_init(char *all_info, char *all_tmap);
    void world_list_destroy(world_t **world_list);
    void world_destroy(world_t *world);
    void world_show(game_t *G, world_t *world);
    speak_t ***world_dialogue_init(char *filepath);
    void world_dialogue_destroy(speak_t ***world_dialogue);

    sfBool player_touch_world(game_t *G, sfVector2f move);
    void animate_npc(game_t *G);
    void show_bubble_speach(game_t *G);
    void world_change(world_t **dest, world_t *src);
    void handle_teleport(game_t *G);

    dialogue_t *dialogue_init(void);
    void dialogue_show(dialogue_t *dialogue, window_t *win);
    void dialogue_destroy(dialogue_t *dialogue);
    void start_npc_dialogue(game_t *G, int npc_id, function_t function);

    speak_t *speak_init(char *info);
    speak_t **speak_list_init(char *filepath);
    void speak_destroy(speak_t *speak);
    void speak_list_destroy(speak_t **speak_list);

    teleport_t *teleport_init(char *info);
    teleport_t **teleport_list_init(char *filepath);
    void teleport_list_destroy(teleport_t **tp_list);
    void teleport_destroy(teleport_t *tp);

    sfRectangleShape *transition_init(void);
    void transition_fade_in(game_t *G);
    void transition_fade_out(game_t *G);
    void transition_fade_in_menu(game_t *G, menu_t *menu);
    void transition_fade_out_menu(game_t *G, menu_t *menu);

    void init_music(game_t *G);
    void destroy_music(game_t *G);

    void wait_animation_end(game_t *G, object_t *obj, function_t function);

    playerbattle_t *player_battle_init(void);
    void player_battle_destroy(playerbattle_t *player);

    battle_t *battle_init(void);
    void battle_start(game_t *G);
    void battle_show(game_t *G);
    void battle_destroy(battle_t *battle);
    void fight_button(game_t *G);
    void shield_button(game_t *G);
    void item_button(game_t *G);

    menu_t *menu_init(char *bg_info, char *button_file,
                                    function_t *functions);
    void menu_show(game_t *G, menu_t *menu);
    void menu_destroy(menu_t *menu);
    void new_game(game_t *G);
    void quit_game(game_t *G);
    void enter_help(game_t *G);

    function_t *function_list_init(void);
    void set_all_world_functions(world_t **world);
    void set_function_forest_1(world_t *world);
    void set_function_forest_2(world_t *world);
    void set_function_forest_3(world_t *world);
    void set_function_forest_4(world_t *world);
    void set_function_forest_5(world_t *world);
    void set_function_casino_1(world_t *world);
    void set_function_casino_2(world_t *world);
    void set_function_casino_3(world_t *world);
    void set_function_casino_4(world_t *world);
    void set_function_casino_5(world_t *world);
    void set_function_desert_1(world_t *world);
    void set_function_desert_2(world_t *world);
    void set_function_desert_3(world_t *world);
    void set_function_desert_4(world_t *world);
    void set_function_desert_5(world_t *world);
    void set_function_tower_1(world_t *world);
    void set_function_tower_2(world_t *world);
    void set_function_tower_3(world_t *world);
    void set_function_tower_4(world_t *world);
    void set_function_tower_5(world_t *world);

#endif
