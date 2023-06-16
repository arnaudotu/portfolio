/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell2-safwane.mkhinini
** File description:
** cd_command
*/

#include "includes.h"

void cd_basic (global_t *global)
{
    char *str = "HOME=";
    node_t *temp = global->head;
    for (; temp != NULL; temp = temp->next) {
        if (my_strncmp(temp->data, str, my_strlen(str)) == 0) {
            chdir(&temp->data[5]);
            return;
        }
    }
    my_printf("cd: No home directory.\n");
}

void cd_dash (global_t *global)
{
    char *str = "OLDPWD";
    node_t *temp = global->head;
    for (; temp != NULL; temp = temp->next) {
        if (my_strncmp(temp->data, str, my_strlen(str)) == 0) {
            chdir(&temp->data[7]);
            return;
        }
    }
    my_printf(": No such file or directory.\n");
}

char *recup_pwd (void)
{
    char* cwd; char *str;
    size_t size = 100;
    while (1) {
        cwd = (char*) malloc(size * sizeof(char));
        if (getcwd(cwd, size) != NULL) {
            str = cwd;
            break;
        }
    }
    return (str);
}

void cd_dash_suit (global_t *global, char *arg)
{
    char *str = recup_pwd(); char *oldpwd = "OLDPWD";
    char *size = malloc(sizeof(char) *
    my_strlen(str) + my_strlen(oldpwd) + 2);
    char *cop_str = my_strcpy(size, oldpwd);
    char *cat_str = my_strcat(cop_str, "=");
    node_t *temp = global->head;
    for (; temp != NULL; temp = temp->next) {
        if (my_strncmp(temp->data, cat_str, my_strlen(cat_str)) == 0) {
            char *cat_str2 = my_strcat(cat_str, str);
            temp->data = cat_str2; int search = chdir(arg);
            if_cond(search, arg);
            return;
        }
    }
    char *cat_str2 = my_strcat(cat_str, str);
    pushback(&global->head, cat_str2); int search = chdir(arg);
    if (search == -1) {
        cd_err(arg); return;
    } return;
}

void check_cond (global_t *global, char *arg)
{
    if (my_strcmp(arg, "-") == 0) {
        cd_dash(global);
    } else {
        cd_dash_suit(global, arg);
    }
}
