/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** absolute_path
*/

#include "includes.h"

char *check_acess (char **arg)
{
    for (int i = 0; arg[i] != NULL; i++) {
        if ((arg[0][i] == '/' || arg[0][i] == '.')
        && access(arg[0], F_OK) == 0) {
            return (arg[i]);
        }
        if (access(arg[i], (X_OK || F_OK)) == 0) {
            return (arg[i]);
        }
    }
    return NULL;
}

int find_char (char **arg)
{
    for (int i = 0; arg[0][i] != '\0'; i++) {
        if (arg[0][i] == '/' || arg[0][i] == '.')
            return 1;
        }
    return 0;
}

int execve_abslte (global_t *global, char **arg)
{
    if (find_char(arg) == 0) return 84;
    int val = 0;
    char **linked_env = linked_transform(global->head);
    char *path = check_acess(arg);
    if (!path) {
        return (84);
    }
    val = execve(path, arg, linked_env);
    execve_error(arg[0], val);
    return 0;
}

void if_cond (int search, char *arg)
{
    if (search == -1) {
        cd_err(arg); return;
    }
}
