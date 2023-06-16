/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

void dialogue_process(game_t *G, speak_t **speak)
{
    int id = G->chat->line;
    if (speak[id] == NULL || !sfRenderWindow_isOpen(G->win->screen)) {
        G->chat->line = 0; return;
    }
    if (check_confirm_input(G)) {
        G->chat->line++;
    }
    sfText_setString(G->chat->text->content, speak[id]->content);
    sfText_setString(G->chat->name->content, speak[id]->name);
    my_object_set_anim(G->chat->obj_list[1], speak[id]->face_id);
    my_object_set_frame(G->chat->obj_list[1], speak[id]->face_frame);
    sfRenderWindow_clear(G->win->screen, sfTransparent);
    world_show(G, G->world);
    dialogue_show(G->chat, G->win);
    my_window_refresh(G->win);
    dialogue_process(G, speak);
}

void start_npc_dialogue(game_t *G, int npc_id, function_t function)
{
    G->in_chat = sfTrue;
    my_object_place(G->chat->obj_list[0], G->win->bottom_left);
    my_object_place(G->chat->obj_list[1], G->win->bottom_left);
    my_object_move(G->chat->obj_list[1], (sfVector2f){30, -25});
    sfVector2f text_pos = G->win->bottom_left;
    text_pos.x += 190; text_pos.y -= 135;
    sfText_setPosition(G->chat->text->content, text_pos);
    text_pos.y -= 50;
    sfText_setPosition(G->chat->name->content, text_pos);
    dialogue_process(G, G->world->npc_speak[npc_id]);
    G->in_chat = sfFalse; G->world->current_npc = npc_id;
    if (function != NULL) {
        function (G);
    }
}
