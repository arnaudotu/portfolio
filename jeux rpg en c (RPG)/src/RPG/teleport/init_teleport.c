/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

teleport_t *teleport_init(char *info)
{
    teleport_t *tp = malloc(sizeof(teleport_t));
    char **tab = my_str_to_array(info, ";");
    sfVector2f pos = {my_str_to_int(tab[0]) * 64, my_str_to_int(tab[1]) * 64};
    sfVector2f size = {my_str_to_int(tab[2]) * 64,
                        my_str_to_int(tab[3]) * 64};
    tp->zone = my_hitbox_init(pos, size, 0);
    tp->tp_pos = (sfVector2f){(my_str_to_int(tab[4]) * 64) + 32,
                        (my_str_to_int(tab[5]) * 64) + 32};
    tp->world_id = my_str_to_int(tab[6]);
    my_free_array(tab);
    return (tp);
}

teleport_t **teleport_list_init(char *filepath)
{
    char **tab = my_str_to_array(my_file_to_str(filepath), "\n");
    teleport_t **tp_list = malloc(sizeof(teleport_t) * my_arraylen(tab));
    for (int i = 0; i < my_arraylen(tab); i++) {
        tp_list[i] = teleport_init(tab[i]);
    }
    tp_list[my_arraylen(tab)] = NULL;
    my_free_array(tab);
    return (tp_list);
}

void teleport_list_destroy(teleport_t **tp_list)
{
    for (int i = 0; tp_list[i] != NULL; i++) {
        teleport_destroy(tp_list[i]);
    }
    free(tp_list);
}

void teleport_destroy(teleport_t *tp)
{
    free(tp);
}
