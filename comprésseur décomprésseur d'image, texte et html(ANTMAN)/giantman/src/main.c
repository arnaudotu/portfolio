/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** main function
*/

#include "../include/giantman.h"

int check_error_file(char *str)
{
    struct stat buf; stat(str, &buf);
    return (S_ISREG(buf.st_mode));
}

int main(int ac, char **av)
{
    if (ac <= 2 || !check_error_file(av[1])) {
        return (84);
    }
    int type = my_str_to_int(av[2]);
    char *str = my_file_to_str(av[1]);
    switch (type) {
        case 1: text_algo(str);
                break;
        case 2: text_algo(str);
                break;
        case 3: image_algo(str);
                break;
    }
    free(str);
    return (0);
}
