/*
** EPITECH PROJECT, 2022
** my_csfml.h
** File description:
** header of my_CSFML related functions
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

//=======================MY_CSFML=================================

typedef struct window_t {
    sfRenderWindow *screen;
    sfView *camera;
    sfVector2f size;
    sfEvent event;
    sfVector2f top_left;
    sfVector2f top_right;
    sfVector2f center;
    sfVector2f bottom_left;
    sfVector2f bottom_right;
    sfClock *clock;
    int fps;
    float tpf;
    sfKeyCode input;
} window_t;

typedef struct audio_t {
    sfSound *sound;
    sfSoundBuffer *buffer;
    sfBool loop;
} audio_t;

typedef struct object_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int pos_id;
    sfVector2f size;
    sfVector2f scale;
    sfFloatRect hitbox;
    sfIntRect frame;
    sfClock *anim_clock;
    int anim_id;
    int anim_tpf;
} object_t;

typedef struct tilemap_t {
    sfRenderStates states;
    sfVertexArray *map;
    int *map_layout;
    int *map_walls;
    sfVector2f pos;
    sfVector2f size;
    sfFloatRect hitbox;
    int tile_size;
} tilemap_t;

typedef struct text_t {
    sfText *content;
    sfFont *font;
    sfColor color;
    int size;
    sfVector2f pos;
} text_t;

/* ====================GAME STRUCTURES BEGINS HERE==================== */

#ifndef MY_CSFML_HEADER_H_
    #define MY_CSFML_HEADER_H_

    //=======================MY_CSFML=================================

    window_t *my_window_init(sfVector2f size, char* name, int fps);
    void my_window_refresh(window_t *window);
    void my_window_check_limit(window_t *window, int x, int y);
    void my_window_change_res(window_t *window, int x, int y);
    void my_window_destroy(window_t *window);

    object_t *my_object_init(char *info);
    void my_object_show(object_t *object, window_t *window);
    void my_object_set_origin(object_t *object, int is_centered);
    void my_object_place(object_t *object, sfVector2f pos);
    void my_object_placetomouse(object_t *object, window_t *window);
    void my_object_change(object_t **dest, object_t *src, int anim);
    void my_object_move(object_t *object, sfVector2f move);
    void my_object_destroy(object_t *object);

    void my_object_set_anim(object_t *object, int anim_id);
    void my_object_animate(object_t *object);
    void my_object_list_animate(object_t **object_list);
    void my_object_set_frame(object_t *object, int n);
    void my_object_update_anim(object_t *object);

    sfIntRect my_rect_sprite_init(sfVector2f size);
    sfFloatRect my_hitbox_init(sfVector2f pos, sfVector2f size, int pos_id);

    void my_event_check(window_t *window);
    void my_event_close_window(window_t *window);

    void my_time_wait(window_t *window, float sec);

    sfBool my_mouse_in_object(window_t *window, object_t *object);
    sfBool my_objects_touch(object_t *one, object_t *two);
    sfBool my_object_touch_list(object_t *one, object_t **list);

    audio_t *my_audio_init(char *file);
    audio_t **my_audio_list_init(char *file);
    void my_audio_play(audio_t *audio);
    void my_audio_wait_end(audio_t *audio);
    void my_audio_destroy(audio_t *audio);
    void my_audio_list_destroy(audio_t **audio_list);

    sfView *my_camera_init(window_t *window);
    void my_camera_change_anchor_points(window_t *window);
    void my_camera_move(window_t *window, sfVector2f move);
    void my_camera_place(window_t *window, sfVector2f pos);

    object_t **my_object_list_init(char *filepath);
    void my_object_list_show(object_t **object_list, window_t *window);
    void my_object_list_destroy(object_t **object_list);

    tilemap_t *my_tilemap_init(char *info);
    int *my_get_tilemap_layout(char *file);
    void my_tilemap_change(tilemap_t **dest, tilemap_t *src);
    void my_tilemap_show(tilemap_t *tilemap, window_t *window);
    void my_tilemap_destroy(tilemap_t *tilemap);

    tilemap_t **my_tilemap_list_init(char *filepath);
    void my_tilemap_list_show(tilemap_t **tilemap_list, window_t *window);
    void my_tilemap_list_destroy(tilemap_t **tilemap_list);

    text_t *my_text_init(char *info);
    void my_text_destroy(text_t *text);

#endif
