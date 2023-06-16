/*
** EPITECH PROJECT, 2022
** my_sort_array_alpha.c
** File description:
** sorts an array in alphabetic order
*/

#include "../../include/my.h"

int check_letter(char letter_first, char letter_j)
{
    if (letter_first < 97) {
        letter_first += 32;
    }
    if (letter_j < 97) {
        letter_j += 32;
    }
    if (letter_first >= 97 && letter_j >= 97) {
        if (letter_first < letter_j) {
            return (0);
        }
        if (letter_first > letter_j) {
            return (1);
        }
    }
}

int check_word_alpha(char **tab, int first, int j)
{
    int check;
    if (my_strlen(tab[first]) < my_strlen(tab[j])) {
        check = first;
    } else {
        check = j;
    }
    for (int letter = 0; tab[check][letter] != '\0'; letter++) {
        if (!my_is_same_letter(tab[first][letter], tab[j][letter])) {
            return (check_letter(tab[first][letter], tab[j][letter]));
        }
    }
    return (0);
}

void check_words(char **tab, int i)
{
    int first = i;
    for (int j = i + 1; tab[j] != NULL; j++) {
        if (check_word_alpha(tab, first, j)) {
            first = j;
        }
    }
    if (first != i) {
        char *temp = malloc(sizeof(first));
        my_strcpy(temp, tab[first]);
        my_strcpy(tab[first], tab[i]);
        my_strcpy(tab[i], temp);
        free(temp);
    }
}

/////////////////////////////////////////
// Sorts the elements of an array in the alphabet orger (maj included)
///\param tab Array to sort
/////////////////////////////////////////
void my_sort_array_alpha(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        check_words(tab, i);
    }
}
