/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell1-safwane.mkhinini
** File description:
** shell
*/

#include "includes.h"

void choose_path (global_t *global, char **arg)
{
    if (execve_abslte(global, arg) == 84) {
        check_command(global, arg);
    }
}

void pointer_array_to_functions (global_t *global)
{
    void *function[] = {exit_command, env_command, unsetenv_command,
    cd_command, setenv_command, cd_dcommand};
    for (int i = 0; i < 6; i++) {
        global->check_tab[i] = function[i];
    }
    void *command_s[] = {"exit", "env", "unsetenv",
    "cd", "setenv", "cd-", NULL};
    for (int j = 0; j < 7; j++) {
        global->command[j] = command_s[j];
    }
}

int main(int argc, char **argv, char **env)
{
    (void) argc; (void) argv; global_t global;
    global.head = NULL; env_list(&global.head, env);
    pointer_array_to_functions(&global);
    while (1) {
        global.buffer = NULL;
        if (isatty(0))
            printf(PROMPT);
        size_t size = 0;
        if (getline(&global.buffer, &size, stdin) == -1) exit (0);
        int len = my_strlen(global.buffer); global.buffer[len - 1] = '\0';
        char **buffer = loop_strtok2(global.buffer, ";");
        check_empty(&global);
        check_smicolon(buffer, &global);
    }
}
