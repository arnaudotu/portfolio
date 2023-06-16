/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of animations
*/

#include "../../include/my_csfml.h"

void my_object_set_anim(object_t *object, int anim_id)
{
    object->anim_id = anim_id;
    object->frame.top = (object->frame.height * anim_id);
    sfSprite_setTextureRect(object->sprite, object->frame);
}

void my_object_animate(object_t *object)
{
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(object->
                                                        anim_clock));
    if (time > object->anim_tpf) {
        my_object_update_anim(object);
        sfClock_restart(object->anim_clock);
    }
}

void my_object_list_animate(object_t **object_list)
{
    for (int i = 0; object_list[i] != NULL; i++) {
        my_object_animate(object_list[i]);
    }
}

void my_object_set_frame(object_t *object, int n)
{
    object->frame.left = object->size.x * n;
    sfSprite_setTextureRect(object->sprite, object->frame);
}

void my_object_update_anim(object_t *object)
{
    if (object->frame.left + 1 >=
                    sfTexture_getSize(object->texture).x - object->size.x) {
        object->frame.left = 0;
    } else {
        object->frame.left += object->size.x;
    }
    sfSprite_setTextureRect(object->sprite, object->frame);
}
