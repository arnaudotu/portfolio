/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** remove_env
*/

#include "includes.h"

// char **arg is not used
int what_redirection(char *buffer, global_t *global, int i)
{
    global->output = STDIN_FILENO;
    if (my_is_str_in_str(buffer, ">") == 1
    && my_is_str_in_str(buffer, ">>") == 0) {
        global->output = STDOUT_FILENO;
        redi_right(buffer, global, O_TRUNC, ">"); exit(1);
    }
    if (my_is_str_in_str(buffer, ">>")) {
        global->output = STDOUT_FILENO;
        redi_right(buffer, global, O_APPEND, ">>");
        exit(1);
    }
    if (my_is_str_in_str(buffer, "<") == 1
    && my_is_str_in_str(buffer, "<<") == 0) {
        global->output = STDIN_FILENO;
        redi_left(buffer, global, O_RDONLY, "<"); exit(1);
    }
    if (my_is_str_in_str(buffer, "<<")) {
        double_redi_left(buffer,global, " <<");
        global->output = STDIN_FILENO; exit(1);
    } return what_redirection_bravo(buffer, global, i);
}

// I did not check other functions, but it could be intresting to return
// The actual command error code. We could then do a "is != that 0"
// to check for errors. To do so, u need to use waitpid instead of wait
int redi_right(char *buffer, global_t *global, int flag, char *sep)
{
    global->file = 0;
    char **tmp; char **arg;
    tmp = loop_strtok2(buffer, sep);
    tmp = clean_str(tmp);
    arg = loop_strtok2(tmp[0], " \t\n");
    char **separate_tmp = loop_strtok2(tmp[1], " \t\n");
    __pid_t pid = fork(); int status;
    if (pid == 0) {
        global->file = open(separate_tmp[0], O_CREAT | O_WRONLY | flag, 0644);
        dup2(global->file, STDOUT_FILENO);
        choose_path(global, arg);
        close(global->file);
        exit(0);
    } else {
        wait(&status);
        kill(pid, SIGKILL);
    }
    return (0);
}

int redi_left(char *buffer, global_t *global, int flag, char *sep)
{
    global->file = 0;
    char **tmp; char **arg;
    tmp = loop_strtok2(buffer, sep);
    tmp = clean_str(tmp);
    arg = loop_strtok2(tmp[0], " \t\n");
    __pid_t pid = fork(); int status;
    if (pid == 0) {
        if (access(tmp[1], R_OK) == 0){
            global->file = open(tmp[1], O_RDONLY, 0644);
            dup2(global->file, STDIN_FILENO);
            choose_path(global, arg);
            close(global->file);
            exit (0);
        } else {
            my_printf("%s: No such file or directory.\n", tmp[1]);
            return 0;
        }
    } else {
        wait (&status); kill (pid, SIGKILL);
    } return (0);
}

int fork_redi_left (global_t *global, char **temp)
{
    temp = loop_strtok2(temp[0], " \t\n");
    char **getline_cont = linked_transform(global->head_red_left);
    int fd[2];
    if (pipe(fd) == -1) {
        printf("An error occurred with opening the pipe\n"); return 1;
    }
    int pid = fork(); int status;
    if (pid == 0) {
        close(fd[0]);
        for (int i = 0; getline_cont[i + 1] != NULL; i++)
            write(fd[1], getline_cont[i], my_strlen(getline_cont[i]));
        close(fd[1]);
    } else {
        waitpid(pid, &status, WAIT_ANY);
        close (fd[1]);
        dup2(fd[0], STDIN_FILENO);
        choose_path(global, temp);
        close(fd[0]);
        kill(pid, SIGKILL);
    } exit(0);
}

int double_redi_left(char *buffer, global_t *global, char *sep)
{
    global->head_red_left = NULL;
    char **temp = loop_strtok2(buffer, sep);
    global->buffer_redi = NULL;
    char *input = malloc(sizeof(char));
    char *str = temp[1];
    while (1) {
        if (isatty(0)) printf("? ");
        size_t size;
        if (getline(&global->buffer_redi, &size, stdin) == -1) exit (0);
        pushback(&global->head_red_left, global->buffer_redi);
        if (my_strncmp(global->buffer_redi, temp[1], my_strlen(temp[1])) == 0) {
            fork_redi_left(global, temp);
            break;
        }
    }
}
