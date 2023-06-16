/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header of the my library
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_H_
    #define MY_H_

    void my_put_char(char c);
    void my_put_str(char const *str);
    void my_put_nbr(int n);
    void my_put_array(char **tab, char *sep, char *end);
    void my_put_float(float f, int dec);
    void my_put_nbr_base(int nbr, char *base);

    int my_char_in_str(char *str, char c);

    int my_strlen(char *str);
    void my_strcpy(char *dest , char const *src);
    void my_strcat(char *dest , char const *src);
    int my_strcmp(char *s1 , char *s2);
    void my_revstr(char *str);

    int my_str_to_int(char *str);
    char **my_str_to_array(char *str, char *sep);
    char *my_file_to_str(char *file);

    int my_arraylen(char **tab);

    void my_free_array(char **tab);

    int my_nbr_min(int a, int b);
    int my_nbr_max(int a, int b);
    int my_nbr_power(int n, int p);

    int my_is_same_letter(char a, char b);

#endif
