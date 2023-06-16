/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

dialogue_t *dialogue_init(void)
{
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));
    dialogue->obj_list =
            my_object_list_init("./assets/dialogue/obj_dialogue_list.csv");
    dialogue->text = my_text_init("./assets/dialogue/font.ttf;50;50;40");
    dialogue->name = my_text_init("./assets/dialogue/font.ttf;50;50;40");
    sfText_setColor(dialogue->name->content, sfYellow);
    dialogue->line = 0;
    return (dialogue);
}

void dialogue_show(dialogue_t *dialogue, window_t *win)
{
    my_object_list_show(dialogue->obj_list, win);
    sfRenderWindow_drawText(win->screen, dialogue->name->content, NULL);
    sfRenderWindow_drawText(win->screen, dialogue->text->content, NULL);
}

void dialogue_destroy(dialogue_t *dialogue)
{
    my_object_list_destroy(dialogue->obj_list);
    my_text_destroy(dialogue->text);
    my_text_destroy(dialogue->name);
    free(dialogue);
}
