/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of sprites
*/

#include "../../include/my_csfml.h"

object_t *my_object_init(char *info)
{
    char **tab = my_str_to_array(info, ";\t ");
    object_t *obj = malloc(sizeof(object_t));
    obj->texture = sfTexture_createFromFile(tab[0], NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->size = (sfVector2f){my_str_to_int(tab[1]), my_str_to_int(tab[2])};
    obj->pos = (sfVector2f){my_str_to_int(tab[3]), my_str_to_int(tab[4])};
    sfVector2f hbox_size = {my_str_to_int(tab[5]), my_str_to_int(tab[6])};
    sfSprite_setPosition(obj->sprite, obj->pos);
    obj->frame = my_rect_sprite_init(obj->size);
    sfSprite_setTextureRect(obj->sprite, obj->frame);
    obj->anim_clock = sfClock_create();
    obj->anim_tpf = my_str_to_int(tab[7]);
    obj->scale = (sfVector2f){my_str_to_int(tab[8]), my_str_to_int(tab[8])};
    sfSprite_setScale(obj->sprite, obj->scale);
    obj->anim_id = 0; obj->pos_id = my_str_to_int(tab[9]);
    obj->hitbox = my_hitbox_init(obj->pos, hbox_size, obj->pos_id);
    my_object_set_origin(obj, obj->pos_id);
    my_free_array(tab); return (obj);
}

void my_object_set_origin(object_t *object, int pos_id)
{
    switch (pos_id) {
        case 0: sfSprite_setOrigin(object->sprite,
                (sfVector2f){object->size.x / 2, object->size.y / 2}); break;
        case 1: sfSprite_setOrigin(object->sprite, (sfVector2f){0, 0}); break;
        case 2: sfSprite_setOrigin(object->sprite,
                (sfVector2f){object->size.x, 0}); break;
        case 3: sfSprite_setOrigin(object->sprite,
                (sfVector2f){0, object->size.y}); break;
        case 4: sfSprite_setOrigin(object->sprite,
                (sfVector2f){object->size.x, object->size.y}); break;
    }; return;
}

void my_object_change(object_t **dest, object_t *src, int anim)
{
    sfVector2f pos = (*dest)->pos;
    if (anim) {
        int frame = (*dest)->frame.left / (*dest)->size.x;
        my_object_set_frame(src, frame);
        my_object_set_anim(src, (*dest)->anim_id);
    }
    (*dest) = src;
    my_object_place((*dest), pos);
}

void my_object_show(object_t *object, window_t *window)
{
    sfRenderWindow_drawSprite(window->screen, object->sprite, NULL);
}

void my_object_destroy(object_t *object)
{
    sfTexture_destroy(object->texture);
    sfSprite_destroy(object->sprite);
    sfClock_destroy(object->anim_clock);
    free(object);
}
