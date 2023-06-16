/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

speak_t ***world_dialogue_init(char *filepath)
{
    char **tab = my_str_to_array(my_file_to_str(filepath), "\n");
    speak_t ***world_dialogue = malloc(sizeof(speak_t**) * my_arraylen(tab));
    for (int i = 0; i < my_arraylen(tab); i++) {
        world_dialogue[i] = speak_list_init(tab[i]);
    }
    world_dialogue[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (world_dialogue);
}

void world_dialogue_destroy(speak_t ***world_dialogue)
{
    if (world_dialogue == NULL) {
        return;
    }
    for (int i = 0; world_dialogue[i] != NULL; i++) {
        speak_list_destroy(world_dialogue[i]);
    }
    free(world_dialogue);
}
