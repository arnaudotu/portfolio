/*
** EPITECH PROJECT, 2022
** my_csfml_rect.c
** File description:
** structure and functions of rect
*/

#include "../../include/my_csfml.h"

sfFloatRect my_hitbox_init(sfVector2f pos, sfVector2f size, int pos_id)
{
    sfFloatRect hitbox;
    hitbox.top = pos.y;
    hitbox.left = pos.x;
    hitbox.width = size.x;
    hitbox.height = size.y;
    switch (pos_id) {
        case 0: hitbox.top -= size.y / 2; hitbox.left -= size.x / 2; break;
        case 1: break;
        case 2: hitbox.left -= size.x; break;
        case 3: hitbox.top -= size.y; break;
        case 4: hitbox.top -= size.y; hitbox.left -= size.x; break;
    };
    return (hitbox);
}

sfIntRect my_rect_sprite_init(sfVector2f size)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = size.x;
    rect.height = size.y;
    return (rect);
}
