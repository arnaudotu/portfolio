/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** cehojfe
*/

#include "includes.h"

int	delimitateur(char s, char *lim)
{
    int   i = 0;

    while (lim[i]) {
        if (s == lim[i])
            return (-1);
        i++;
    }
    return (0);
}

int	boucle_delimitateur(char const *str, int i, char *lim)
{
    if (delimitateur(str[i], lim) == -1) {
        while (delimitateur(str[i], lim) == -1)
            i++;
        i -= 1;
    }
    return (i);
}

int nbr_of_word(char const *str, char *lim)
{
    int     i = 0;
    int	res = 1;

    while (str[i] != '\0') {
        i = boucle_delimitateur(str, i, lim);
        res += 1;
        i++;
    }
    return (res);
}

int	word_size(char *str, int i, char *lim)
{
    int	len = 0;

    while (delimitateur(str[i], lim) == 0 && str[i]) {
        len++;
        i++;
    }
    return (len);
}

char **my_str_to_word_array(char *str, char *lim)
{
    int	nb_word = nbr_of_word(str, lim) + 2;
    int	i = 0;
    char **tab;
    int	y = 0; int x = 0;

    tab = malloc(sizeof(char*) * nb_word + 1);
    while (str[i] != '\0') {
        x = 0;
        for (i = i; ((delimitateur(str[i], lim) == -1) &&
        (str[i] != '\0')); i++);
            tab[y] = malloc(sizeof(char) * (word_size(str, i, lim) + 1));
        for (i = i; ((delimitateur(str[i], lim) == 0) &&
        (str[i] != '\0')); i++ , x++){
            tab[y][x] = str[i];
        }
        tab[y][x] = '\0';
        y++;
    }
    tab[y] = NULL;
    return (tab);
}
