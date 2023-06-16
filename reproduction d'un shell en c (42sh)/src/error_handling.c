/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** error_handling
*/

#include "includes.h"

void signal_error (int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        write(2, "Segmentation fault", 18);
        if (WCOREDUMP(status)) {
            write(2, " (core dumped)", 14);
        }
        my_putchar('\n');
    }

    if (WTERMSIG(status) == SIGFPE) {
        write(2, "Floating exception", 18);
        if (WCOREDUMP(status)) {
            write(2, " (core dumped)", 14);
        }
        my_putchar('\n');
    }
}

void execve_error (char *arg, int val)
{
    if (val == -1 && errno == EACCES) {
            write(2, arg, my_strlen(arg));
            write(2, ": Permission denied.\n", 21);
        return;
    }
    if (val == -1 && errno == ENOEXEC) {
        write(2, arg, my_strlen(arg));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
    }
}
