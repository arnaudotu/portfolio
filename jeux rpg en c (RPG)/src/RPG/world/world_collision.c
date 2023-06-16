/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfBool player_touch_world(game_t *G, sfVector2f move)
{
    sfFloatRect h_box_move = G->player->obj->hitbox;
    h_box_move.left += move.x; h_box_move.top += move.y;
    for (int i = 0; G->world->npc_list[i] != NULL; i++) {
        if (sfFloatRect_intersects(&h_box_move,
            &G->world->npc_list[i]->hitbox, NULL)
            && G->world->npc_switch[i] == 0) {
            return (sfTrue);
        }
    }
    return (sfFalse);
}

void world_change(world_t **dest, world_t *src)
{
    (*dest) = src;
}

void show_bubble_speach(game_t *G)
{
    sfVector2f bubble_pos;
    sfFloatRect h_box_extend = G->player->obj->hitbox;
    h_box_extend.left -= 10; h_box_extend.top -= 10;
    h_box_extend.width += 20; h_box_extend.height += 20;
    for (int i = 0; G->world->npc_list[i] != NULL; i++) {
        if (sfFloatRect_intersects(&h_box_extend,
            &G->world->npc_list[i]->hitbox, NULL)
            && G->world->npc_switch[i] == 0) {
            bubble_pos = G->world->npc_list[i]->pos;
            bubble_pos.y -= G->world->npc_list[i]->size.y * 2.5;
            my_object_place(G->bubble, bubble_pos);
            my_object_show(G->bubble, G->win);
            my_object_animate(G->bubble);
        }
    }
}

void animate_npc(game_t *G)
{
    sfFloatRect h_box_extend = G->player->obj->hitbox;
    h_box_extend.left -= 10; h_box_extend.top -= 10;
    h_box_extend.width += 20; h_box_extend.height += 20;
    for (int i = 0; G->world->npc_list[i] != NULL; i++) {
        if (sfFloatRect_intersects(&h_box_extend,
            &G->world->npc_list[i]->hitbox, NULL)
            && check_confirm_input(G) && !G->in_chat) {
                start_npc_dialogue(G, i, G->world->npc_fct[i]);
        }
        if (G->in_chat) {
            my_object_animate(G->world->npc_list[i]);
        } else {
            my_object_set_frame(G->world->npc_list[i], 0);
        }
    }
}

void handle_teleport(game_t *G)
{
    for (int i = 0; G->world->tp_list[i] != NULL; i++) {
        if (sfFloatRect_intersects(&G->player->obj->hitbox,
            &G->world->tp_list[i]->zone, NULL)
            && G->in_teleport == sfFalse) {
            G->in_teleport = sfTrue;
            transition_fade_in(G);
            int world_tp_id = G->world->tp_list[i]->world_id;
            my_object_place(G->player->obj, G->world->tp_list[i]->tp_pos);
            my_camera_place(G->win, G->world->tp_list[i]->tp_pos);
            world_change(&G->world, G->world_list[world_tp_id]);
            fix_camera(G, (sfVector2f){0, 0});
            transition_fade_out(G);
            i = 0;
            G->in_teleport = sfFalse;
        }
    }
}
