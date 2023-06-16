/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell1-safwane.mkhinini
** File description:
** tab
*/

#include "includes.h"

void check_command (global_t *global, char **arg)
{
    for (int i = 0; global->command[i] != NULL; i++) {
        if (my_strcmp(arg[0], global->command[i]) == 0) {
            (global->check_tab[i])(global, arg); exit(0);
        }
    }
    char **linked_env = linked_transform(global->head);
    char *path = path_recup(linked_env, arg);
    if (!path) {
        char **arr = loop_strtok2(global->buffer, " \t\n");
        my_printf("%s: Command not found.\n", arr[0]); exit(1);
    }
    execve(path, arg, linked_env); free(linked_env); free(path);
}
