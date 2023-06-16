/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

speak_t *speak_init(char *info)
{
    speak_t *speak = malloc(sizeof(speak_t));
    char **tab = my_str_to_array(info, ";");
    speak->name = malloc(sizeof(char) * 1000); speak->name[0] = '\0';
    my_strcpy(speak->name, tab[0]);
    speak->face_id = my_str_to_int(tab[1]);
    speak->face_frame = my_str_to_int(tab[2]);
    speak->content = malloc(sizeof(char) * 1000); speak->content[0] = '\0';
    my_strcpy(speak->content, tab[3]);
    my_free_array(tab);
    return (speak);
}

speak_t **speak_list_init(char *filepath)
{
    char **tab = my_str_to_array(my_file_to_str(filepath), "\n");
    speak_t **speak_list = malloc(sizeof(speak_t) * my_arraylen(tab));
    for (int i = 0; i < my_arraylen(tab); i++) {
        speak_list[i] = speak_init(tab[i]);
    }
    speak_list[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (speak_list);
}

void speak_destroy(speak_t *speak)
{
    free(speak->content);
    free(speak->name);
    free(speak);
}

void speak_list_destroy(speak_t **speak_list)
{
    if (speak_list == NULL) {
        return;
    }
    for (int i = 0; speak_list[i] != NULL; i++) {
        speak_destroy(speak_list[i]);
    }
    free(speak_list);
}
