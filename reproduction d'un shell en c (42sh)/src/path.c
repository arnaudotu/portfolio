/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell1-safwane.mkhinini
** File description:
** path
*/

#include "includes.h"

int check_path (char *path, char *cmd)
{
    DIR *dir = opendir(path);
    if (dir == NULL)
        return 84;
    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (my_strcmp(entity->d_name, cmd) == 0) {
            return 0;
        }
        entity = readdir(dir);
    }
    return 1;
}

char *browse_loop(char *env, char **cmd)
{
    char **arr = loop_strtok(env);
    for (int j = 0; arr[j] != NULL; j++) {
        if (check_path(arr[j], cmd[0]) == 0) {
            char *str = malloc(sizeof(char) *
            (my_strlen(arr[j]) + 1 + my_strlen(cmd[0])) + 1);
            str[0] = '\0';
            my_strcat(my_strcat(my_strcat(str, arr[j]), "/"), cmd[0]);
            return str;
        }
    }
    return NULL;
}

char *path_recup (char **env, char **cmd)
{
    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], "PATH", 4) == 0)
            return browse_loop(env[i], cmd);
    return NULL;
}
