/*
** EPITECH PROJECT, 2022
** my_is_file.c
** File description:
** Checks if a path is a directory
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks if a path is a directory
///\param file Path of the directory from the program's executable
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_directory(char *file)
{
    struct stat buf; stat(file, &buf);
    return (S_ISDIR(buf.st_mode));
}
