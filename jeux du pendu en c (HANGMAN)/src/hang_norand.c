/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
**
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <sys/stat.h>
#include <unistd.h>

int hang_norand(char **buffer, word_t *word, int try, int nb)
{
    int e = 0;
    word->try = try;
    word->full_word = buffer[nb];
    word->hidden_word = full_star_word(word->full_word);
    word->word_temp = word->hidden_word;
    printf("%s\nTries: %d\n\n", word->hidden_word, try);
    for (;word->try != 0;e++) {
        char result = getch();
        word->word_temp = letter_in_word(word, result);
        printf("%s\n", word->word_temp);
        printf("Tries: %d\n\n", word->try);
        if (if_win(word) == 1){
            return 1;
        }
    } return 0;
}
