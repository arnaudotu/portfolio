/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** error_handling
*/

#include "includes.h"

int error_case (char *arg)
{
    if ((arg[0] < 65 || arg[0] > 90 )
    && (arg[0] < 97 || arg[0] > 122)) {
        return 1;
    }
    return 0;
}

int alpha_case (char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if ((arg[i] < 65 || arg[i] > 90 )
        && (arg[i] < 97 || arg[i] > 122)
        && (arg[i] < 48 || arg[i] > 57 )) {
            return 1;
        }
    }
    return 0;
}

void print_error_alpha (void)
{
    my_printf("setenv: Variable name must contain alphanumeric characters.\n");
    return;
}

void print_error (void)
{
    my_printf("setenv: Variable name must begin with a letter.\n");
    return;
}

void cd_err (char *arg)
{
    my_printf("%s: Not a directory.\n", arg);
    return;
}
