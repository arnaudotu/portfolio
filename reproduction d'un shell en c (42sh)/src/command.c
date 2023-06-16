/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** command
*/

#include "includes.h"

void env_command(global_t *global, char **arg)
{
    (void) arg;
    print_list(global->head);
}

void exit_command(global_t *global, char **arg)
{
    (void) arg;
    global = global;
    exit(0);
}

void setenv_command (global_t *global, char **arg)
{
    int j = 0; for (; arg[j] != NULL;) j++;
    if (j > 3) my_printf("setenv: Too many arguments.\n");
    if (j == 1) print_list(global->head);
    if (j == 2) {
        for (int i = 1; arg[i] != NULL; i++) {
            add_name(global, arg[i]);
        }
    }
    if (j == 3) {
        for (int i = 1; arg[i] != NULL; i++) {
            add_node(global, arg, i);
            return;
        }
    }
}

void unsetenv_command(global_t *global, char **arg)
{
    int j = 1;
    for (; arg[j] != NULL; j++) {
        remove_node(global, arg[j]);
    }
}

void cd_command (global_t *global, char** arg)
{
    int i = 0; for (; arg[i] != NULL;) i++;
    if (i > 2) my_printf("cd: Too many arguments.\n");
    if (i == 1) {
        cd_basic(global);
    }
    if (i == 2) {
        for (int i = 1; arg[i] != NULL; i++) {
            check_cond(global, arg[i]);
        }
    }
}
