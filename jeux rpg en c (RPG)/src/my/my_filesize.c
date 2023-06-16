/*
** EPITECH PROJECT, 2022
** my_is_file.c
** File description:
** Checks if a path is a file
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns a file's size in bits
///\param file Path of the file from the program's executable
///\return File size in bits
/////////////////////////////////////////
int my_filesize(char *file)
{
    struct stat buf; stat(file, &buf);
    off_t size = buf.st_size;
    return (size);
}
