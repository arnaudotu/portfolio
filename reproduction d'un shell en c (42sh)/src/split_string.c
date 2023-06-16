/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-safwane.mkhinini
** File description:
** split_string
*/

#include "includes.h"

int count_word (char *str, char *delim)
{
    int word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; delim[j] != '\0'; j++) {
            (str[i] == delim[j]) ? word++ : 0;
        }
    }
    return (word + 1);
}

char **loop_strtok (char *str)
{
    char *delim = " \t\n:="; char *token;
    int word = 0;
    int count = count_word (str, " \t:=");
    char **arr = malloc(sizeof(char *) * (count + 1));
    token = strtok(str, delim);
    while (token != NULL) {
        arr[word] = my_strdup(token);
        token = strtok(NULL, delim);
        word++;
    }
    arr[word] = NULL;
    return (arr);
}

char **loop_strtok2 (char *str, char *delim)
{
    char *temp = my_strdup(str);
    char *token;
    int word = 0;
    int count = count_word (temp, " \t:=");
    char **arr = malloc(sizeof(char *) * (count + 1));
    token = strtok(temp, delim);
    while (token != NULL) {
        arr[word] = my_strdup(token);
        token = strtok(NULL, delim);
        word++;
    }
    arr[word] = NULL;
    return (arr);
}
