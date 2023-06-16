/*
** EPITECH PROJECT, 2022
** my_csfml_rect.c
** File description:
** structure and functions of rect
*/

#include "../../include/my_csfml.h"

text_t *my_text_init(char *info)
{
    text_t *text = malloc(sizeof(text_t));
    char **tab = my_str_to_array(info, ";");
    sfVector2f pos = {my_str_to_int(tab[1]), my_str_to_int(tab[2])};
    int size = my_str_to_int(tab[3]);
    sfFont *font = sfFont_createFromFile(tab[0]);
    text->content = sfText_create();
    sfText_setCharacterSize(text->content, size);
    sfText_setFont(text->content, font);
    sfText_setColor(text->content, sfWhite);
    sfText_setPosition(text->content, pos);
    my_free_array(tab);
    return (text);
}

void my_text_destroy(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->content);
    free(text);
}
