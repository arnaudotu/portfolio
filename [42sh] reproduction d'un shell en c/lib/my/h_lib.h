/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Main lib file (prototyping all functions)
*/

#ifndef INCLUDED_LIB_LIB_H
    #define INCLUDED_LIB_LIB_H

    #include "includes.h"

m_box               my_create_box(char *name, void *value, char *type);
void                my_delet_box(m_box box);

void                my_putstr_color_fd(char *str, char *color, int fd);
void                my_putstr_color(char *str, char *color);

void                dev_my_debug(m_box var, int line, char *file);
void                dev_my_debug_custom(m_box var, int line,
    char *file, void (*func)(void *));

int                 my_getnbr_raw(const char *str);
int                 my_getnbr(const char *str);
int                 my_get_unsigned_nbr(const char *str);

int                 my_pow(int x, int power);
bool                my_is_prime(int nb);

void                my_memset(char *buff, char c, int size);
char               *my_add_size(char *buffer, int size, bool was_malloced);

void                my_putchar_fd(char c, int fd);
void                my_putchar(char c);

void                my_putnbr_base_fd(int nbr, const char *base, int fd);
void                my_putnbr_base(int nbr, const char *base);

void                my_putnbr_fd(int nbr, int fd);
void                my_putnbr(int nbr);

void                my_putstr_fd(const char *str, int fd);
void                my_putstr(const char *str);

void                my_showstr_fd(const char *str, int fd);
void                my_showstr(const char *str);

int                 my_str_get_index(const char *str, char c);
bool                my_str_are_only(const char *str, const char *ref);

char               *my_strcapitalize(char *str);

bool                my_str_is_letters(const char *str);
bool                my_str_is_numbers(const char *str);
bool                my_str_is_upper(const char *str);
bool                my_str_is_lower(const char *str);

int                 my_str_count(const char *str, char c);
int                 my_str_counts(const char *_str, const char *sub);

int                 my_str_find(char *str, const char *sub);

char               *my_str_join(char **map, const char *join);

char               *my_str_replace(char *str, char *sep, char *to);

char              **my_str_split(char *str, const char *sub);

char               *my_strcat(char *dest, const char *src);
char               *my_strncat(char *dest, const char *src, int n);

int                 my_strcmp(const char *s1, const char *s2);
int                 my_strncmp(const char *s1, const char *s2, int n);

char               *my_strcpy(char *dest, const char *src);
char               *my_strncpy(char *dest, const char *src, int n);

char               *my_strdup(const char *str);
char               *my_strndup(const char *str, int n);

int                 my_strlen(const char *str);
int                 my_strlen_to_char(const char *str, char c);

void                my_swap(int *a, int *b);

char                **clean_str(char **str);

char                **my_str_to_word_array(char *str, char *lim);

int                 my_is_str_in_str(char *str, char *elem);

#endif
