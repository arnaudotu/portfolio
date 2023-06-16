/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header of my library functions
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_H_
    #define MY_H_

    char **my_str_to_array(char *str, char *sep);
    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_putnbr(int n);
    void my_put_array(char **tab, char *sep, char *end);
    void my_putfloat(float f, int dec);
    void my_putnbr_base(int nbr, char *base);

    int my_char_in_str(char *str, char c);

    int my_strlen(char *str);
    void my_strcpy(char *dest , char const *src);
    void my_strcat(char *dest , char const *src);
    int my_strcmp(char *s1 , char *s2);
    void my_revstr(char *str);

    int my_str_to_int(char *str);
    char **my_str_to_array(char *str, char *sep);
    char *my_file_to_str(char *file);
    int my_int_to_binary(int n);

    int my_arraylen(char **tab);
    int my_nbrlen(int n);

    void my_free_array(char **tab);

    int my_nbr_min(int a, int b);
    int my_nbr_max(int a, int b);
    int my_nbr_power(int n, int p);

    int my_is_same_letter(char a, char b);
    int my_is_number(char *str);
    int my_is_float(char *str);
    int my_is_letter(char c);
    int my_is_word(char *str);
    int my_is_file(char *file);
    int my_is_directory(char *file);
    int my_is_between(int n, int min, int max);

    void my_sort_array_alpha(char **tab);
    int my_is_str_in_str(char *str, char *elem);
    int my_is_str_in_array(char **tab, char *str);

    int my_filesize(char *file);
    int my_binary_to_nbr(int n);

#endif
