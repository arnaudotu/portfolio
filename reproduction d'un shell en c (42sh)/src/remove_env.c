/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** remove_env
*/

#include "includes.h"

void check_empty (global_t *global)
{
    char *path = "PATH= /usr/bin:/usr/local:bin";
    char *pwd = recup_pwd();
    char *str = "PWD=";
    char *memo = malloc(sizeof(char) * my_strlen(pwd) + my_strlen(str) + 2);
    char *cop_str = my_strcpy(memo, str);
    char *cat_str = my_strcat(cop_str, pwd);
    if (global->head == NULL) {
        pushback(&global->head, path);
        pushback(&global->head, cat_str);
    }
    node_t *tmp = global->head;
    int is_path = 0, is_pwd = 0;
    for (; tmp->next; tmp = tmp->next) {
        if (my_strncmp(tmp->data, "PATH=", 5) == 0) is_path = 1;
        if (my_strncmp(tmp->data, "PWD=", 4) == 0) is_pwd = 1;
    }
    if (!is_path) pushback(&global->head, path);
    if (!is_pwd) pushback(&global->head, cat_str);
}
