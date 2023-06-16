/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description: main
**
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

char *get_word(char **buffer)
{
    int i = 0;
    for (;buffer[i] != NULL;i++) {
    }
    srand(time(NULL));
    int nb = rand() % i;
    return buffer[nb];
}

int get_nb(char **buffer)
{
    int i = 0;
    for (;buffer[i] != NULL;i++) {
    }
    srand(time(NULL));
    int nb = rand() % i;
    return nb;
}

word_t *init_struct(char **argv)
{
    word_t *word = malloc(sizeof(word_t));
    word->hidden_word = NULL;
    word->full_word = NULL;
    word->word_temp = NULL;
    word->try = 0;
    return word;
}

void free_tab(word_t *word)
{
    free(word->hidden_word);
    free(word->full_word);
}

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3 && argc != 4) return 84;
    int status = 0;
    int fd = open(argv[1], O_RDONLY);
    if (fd != 3) return 84;
    word_t *word = init_struct(argv);
    struct stat st; char *buffer; stat(argv[1], &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buffer, st.st_size); buffer[st.st_size] = '\0';
    char **stockbuff = my_str_to_word_array(buffer, "\n");
    if (argc == 2) status = hang_rand(stockbuff, word);
    if (argc == 3)
        status = hang_norand(stockbuff, word, atoi(argv[2]), get_nb(stockbuff));
    if (argc == 4)
        status = hang_norand(stockbuff, word, atoi(argv[2]), atoi(argv[3]));
    if (status == 0) printf("You lost!\n");
    else {
        printf("Congratulations!\n");
    }free(buffer);free_tab(word);free(word);
    return 0;
}
