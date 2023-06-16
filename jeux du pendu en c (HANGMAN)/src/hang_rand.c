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

char getch(void)
{
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters = 0;
    buffer = (char*)malloc(bufsize * sizeof(char));
    if (!buffer) return 0;
    printf("Your letter: ");
    characters = getline(&buffer, &bufsize, stdin);
    if (characters == -1) return 0;
    char tmp = buffer[0];
    free(buffer);
    return tmp;
}

int if_win(word_t *word)
{
    char *temp_word = word->word_temp;
    for (int i = 0;temp_word[i] != '\0';i++) {
        if (temp_word[i] == '*')
            return 0;
    }
    return 1;
}

int hang_rand(char **buffer, word_t *word)
{
    int e = 0;
    word->try = 10;
    word->full_word = get_word(buffer);
    word->hidden_word = full_star_word(word->full_word);
    word->word_temp = word->hidden_word;
    printf("%s\nTries: 10\n\n", word->hidden_word);
    for (;word->try != 0;e++) {
        char result = getch();
        word->word_temp = letter_in_word(word, result);
        printf("%s\n", word->word_temp);
        printf("Tries: %d\n\n", word->try);
        if (if_win(word) == 1)
            return 1;
    }
}
