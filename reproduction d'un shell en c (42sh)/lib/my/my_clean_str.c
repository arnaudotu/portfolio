/*
** EPITECH PROJECT, 2023
** clean_str.c
** File description:
** poijhou
*/

#include "includes.h"

char **if_first_space(char **str, int i, int f)
{
    if (str[i][0] == ' ' || str[i][0] == '\n'){
        while (str[i][f] != '\0'){
            str[i][f] = str[i][f + 1];
            f++;
        }
        str[i][f] = '\0';
    }
}

char *if_last_space(char **str, int i, int p)
{
    int len = 0; len = my_strlen(str[i]);
    if (str[i][len - p] == ' ' || str[i][0] == '\n'){
        while (str[i][len - p] == ' '){
            str[i][len - p] = '\0';
            p++;
        }
    }
}

char **clean_str(char **str)
{
    int i = 0; int f = 0; int p = 1;
    while (str[i] != NULL){
        if_first_space(str, i, f);
        if_last_space(str, i, p);
        i++;
    }
    return str;
}
