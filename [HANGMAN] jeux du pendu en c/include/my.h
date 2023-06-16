/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** my_h
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib.h"
#include <sys/types.h>
#include <sys/stat.h>

typedef struct word_s {
    char *hidden_word;
    char *full_word;
    char *word_temp;
    int try;
} word_t;

#ifndef MY_H_
    #define MY_H_
    int hang_rand(char **buffer, word_t *word);
    int hang_norand(char **buffer, word_t *word, int try, int nb);
char *letter_in_word(word_t *word,char your_letter);
    char getch(void);
    char *get_word(char **buffer);
    char  *full_star_word(char *word);
    int if_win(word_t *word);
#endif /* MY_H_ */
