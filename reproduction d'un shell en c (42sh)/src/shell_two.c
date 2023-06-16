/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** semicolon
*/

#include "includes.h"

int shell_start(char *buffer, global_t *global, int i)
{
    char **arg = loop_strtok2(buffer, " \t\n:");
    for (int i = 0; global->command[i] != NULL; i++) {
        if (my_strcmp(arg[0], global->command[i]) == 0) {
            global->check_tab[i](global, arg);
            return (0);
        }
    }
    pid_t pid; int status;
    pid = fork();
    if (pid == 0) {
        if (what_redirection(buffer, global, i) == 0){
            choose_path(global, arg);
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) == 1) {
            signal_error(status);
        }
        kill(pid, SIGKILL);
    }
}

void check_smicolon (char **buffer, global_t *global)
{
    for (int i = 0; buffer[i] != NULL; i++) {
        if (my_strcmp(buffer[i], "exit") == 0) {
            exit(0);
        }
        if (buffer[i][0] == '\n') continue;
        shell_start(buffer[i], global, i);
    }
}
