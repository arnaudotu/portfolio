/*
** EPITECH PROJECT, 2022
** my_file_to_str.c
** File description:
** turns a file content into a str
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns a file content into a string (must be freed after use)
///\param filepath Path of the file from the program's executable
///\return String containing the file's content
/////////////////////////////////////////
char *my_file_to_str(char *filepath)
{
    struct stat buf; stat(filepath, &buf);
    off_t size = buf.st_size;
    int file = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * (size + 1));
    read(file, buff, buf.st_size);
    buff[size] = '\0';
    close(file);
    return (buff);
}
