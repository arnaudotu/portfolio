/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** my_h
*/

#include <stdarg.h>
#include <string.h>

#ifndef LIB_H_
    #define LIB_H_
    char *my_strdup(char const *src);
    char *read_file(char *filepath);
    int create_tab(char **file);
    char **my_str_to_word_array(char const *str, char *delim);
    int **my_str_to_int_array(char const *str, char *delim);
    char **read_file_to_array(char *filepath, char *delim);
    int cmptdir(int argc, char **argv);
    int cmptdigit(int n);
    int cmptdir(int argc, char **argv);
    char *my_intchar(int n);
    int cmptblock(char **argv, int j, int cmptdir);
    void my_sort_alphabet(char *str);
    int my_printf(const char *format,...);
    int pourf(va_list args);
    int my_put_nbr_float(double nb);
    int pourllu(va_list args);
    int pourhu(va_list args);
    int pourlli(va_list args);
    int pourli(va_list args);
    int pourhi(va_list args);
    int pourb(va_list args);
    int revstr(va_list args);
    int hexaint(va_list args);
    int octal(va_list args);
    int pourc(va_list args);
    int pourdi(va_list args);
    int u_octal(va_list args);
    int pourcent(va_list args);
    int pourui(va_list args);
    int pourn(va_list args);
    int pours(va_list args);
    int my_print_alpha(void);
    int my_print_digits(void);
    int my_print_revalpha(void);
    void my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    int my_islower(char c);
    int my_isupper(char c);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    int my_showstr(char const *str);
    int my_showmem(char const *str, int size);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);
    char* my_intchar(int N);
    void replace_char(char *str, char split, char replace);
    int count_line(const char *str);
    void my_clear_str(char *str);
#endif /* LIB_H_ */
