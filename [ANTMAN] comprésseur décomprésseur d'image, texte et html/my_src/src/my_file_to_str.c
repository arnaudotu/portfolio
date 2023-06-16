/*
** EPITECH PROJECT, 2022
** my_file_to_str.c
** File description:
** turns a file content into a str
*/

#include "../include/my.h"

char *my_file_to_str(char *filepath)
{
    struct stat buf; stat(filepath, &buf);
    off_t size = buf.st_size;
    int file = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * (size + 1));
    read(file, buff, buf.st_size);
    buff[size] = '\0';
    return (buff);
}
