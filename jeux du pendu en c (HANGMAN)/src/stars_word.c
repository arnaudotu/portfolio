/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description: stars_word
**
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <sys/stat.h>
#include <unistd.h>


char* full_star_word(char *word)
{
    int len = strlen(word);
    char *full_star_word = malloc(sizeof(char) * (len + 1));
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        full_star_word[i] = '*';
    }
    full_star_word[i] = '\0';
    return full_star_word;
}

char *letter_in_word(word_t *word, char letter)
{
    char *temp_word = word->word_temp;
    char *full_word = word->full_word;
    int len = strlen(full_word);
    bool passed = false;
    for (int i = 0;full_word[i] != '\0';i++) {
        if (full_word[i] == letter) {
            temp_word[i] = full_word[i];
            passed = true;
        } if (temp_word[i] == '*' && full_word[i] != letter)
            temp_word[i] = '*';
    }
    if (passed != true) {
        printf("%c: is not in this word\n", letter);
        word->try--;
    }
    return temp_word;
}
