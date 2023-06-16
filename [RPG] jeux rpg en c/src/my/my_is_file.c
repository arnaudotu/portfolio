/*
** EPITECH PROJECT, 2022
** my_is_file.c
** File description:
** Checks if a path is a file
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks if a path is a file
///\param file Path of the file from the program's executable
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_file(char *file)
{
    struct stat buf; stat(file, &buf);
    return (S_ISREG(buf.st_mode));
}
