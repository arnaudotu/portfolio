/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void wait_animation_end(game_t *G, object_t *obj, function_t function)
{
    my_object_animate(obj);
    if (obj->frame.left == 0) {
        return;
    }
    function (G);
    wait_animation_end(G, obj, function);
}
