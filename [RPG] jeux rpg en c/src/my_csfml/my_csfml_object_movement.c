/*
** EPITECH PROJECT, 2022
** my_csfml_sprite_movement.c
** File description:
** structure and functions of sprites
*/

#include "../../include/my_csfml.h"

void my_object_move(object_t *object, sfVector2f move)
{
    object->pos.x += move.x;
    object->pos.y += move.y;
    object->hitbox.top += move.y;
    object->hitbox.left += move.x;
    sfSprite_move(object->sprite, move);
}

void my_object_place(object_t *object, sfVector2f pos)
{
    object->pos.x = pos.x;
    object->pos.y = pos.y;
    object->hitbox.top = pos.y;
    object->hitbox.left = pos.x;
    switch (object->pos_id) {
        case 0: object->hitbox.top -= object->hitbox.height / 2;
                object->hitbox.left -= object->hitbox.width / 2; break;
        case 1: break;
        case 2: object->hitbox.left -= object->hitbox.width; break;
        case 3: object->hitbox.top -= object->hitbox.height; break;
        case 4: object->hitbox.top -= object->hitbox.height;
                object->hitbox.left -= object->hitbox.width; break;
    };
    sfSprite_setPosition(object->sprite, pos);
}

void my_object_placetomouse(object_t *object, window_t *window)
{
    object->pos.x =
        sfMouse_getPositionRenderWindow(window->screen).x
                - (object->size.x / 2);
    object->pos.y =
        sfMouse_getPositionRenderWindow(window->screen).y
                - (object->size.y / 2);
    my_object_place(object, object->pos);
}
