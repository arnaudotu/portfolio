/*
** EPITECH PROJECT, 2023
** main
** File description:
** redirections_bravo
*/

#include "includes.h"

int sample_exec_cmd(global_t *global, char *cmd)
{
    char **splited = loop_strtok2(cmd, " \t\n");
    __pid_t pid = fork(); int status = 0;
    if (pid == 0) {
        choose_path(global, splited);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        kill(pid, SIGKILL);
    }
    return status;
}

void dble_and_redirection(char *buffer, global_t *global)
{
    char **both_commands = my_str_split(buffer, "&&");
    if (sample_exec_cmd(global, both_commands[0]) == 0)
        sample_exec_cmd(global, both_commands[1]);
}

void dble_or_redirection(char *buffer, global_t *global)
{
    char **both_commands = my_str_split(buffer, "||");
    if (sample_exec_cmd(global, both_commands[0]) != 0)
        sample_exec_cmd(global, both_commands[1]);
}

int what_redirection_bravo(char *buffer, global_t *global, int i)
{
    global->output = STDIN_FILENO;
    if (my_str_find(buffer, "&&") != -1) {
        global->output = STDOUT_FILENO;
        dble_and_redirection(buffer, global); exit(1);
    }
    if (my_str_find(buffer, "||") != -1) {
        global->output = STDOUT_FILENO;
        dble_or_redirection(buffer, global); exit(1);
    }
    return 0;
}
