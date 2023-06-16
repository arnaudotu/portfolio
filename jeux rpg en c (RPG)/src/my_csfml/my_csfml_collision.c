/*
** EPITECH PROJECT, 2022
** my_csfml_sprite.c
** File description:
** structure and functions of collisions
*/

#include "../../include/my_csfml.h"

sfBool my_mouse_in_object(window_t *window, object_t *object)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window->screen,
            sfMouse_getPositionRenderWindow(window->screen), window->camera);
    sfFloatRect hitbox = sfSprite_getGlobalBounds(object->sprite);
    if (mouse.x > hitbox.left
        && mouse.x < object->hitbox.left + object->hitbox.width
        && mouse.y > object->hitbox.top
        && mouse.y < object->hitbox.top + object->hitbox.height) {
            return (1);
    }
    if (sfEvtMouseButtonReleased) {
        return (0);
    }
    return (0);
}

sfBool my_objects_touch(object_t *one, object_t *two)
{
    return (sfFloatRect_intersects(&one->hitbox, &two->hitbox, NULL));
}

sfBool my_object_touch_list(object_t *one, object_t **list)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (my_objects_touch(one, list[i])) {
            return (sfTrue);
        }
    }
    return (sfFalse);
}
