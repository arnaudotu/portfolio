/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** arnaud_niclot
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/struct.h"
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef MY_H_
    #define MY_H_

void *my_putstr(char *str);
void *my_putchar(char c);
int my_putnbr(int nb);
int my_strlen_int(int *str);
int my_putnbr_base (int nbr, char const *base);
int hexa (int n);
int octal (int n);
int hexa_maj (int n);
int binary (int n);
int my_putnbr_u(unsigned int nb);
int my_putstr_maj(char const *str);
int my_put_pointeur(long long p);
int my_put_float(double nb);

void *algo(list_t *list);
int algo_court(list_t *list);
void *suite_algo1(list_t *list);
void *suite_algo2(list_t *list);
int check_list(list_t *list, int argc);
int is_sorted(list_t *list);
int list_sorted(list_t *list);
int print_space(list_t *list);
void check_b(list_t *list);

void sa_opperation(list_t *list);
void sb_opperation(list_t *list);
void sc_opperation(list_t *list);
void pa_opperation(list_t *list);
void pb_opperation(list_t *list);
void ra_opperation(list_t *list);
void rb_opperation(list_t *list);
void rr_opperation(list_t *list);
void rra_opperation(list_t *list);
void rrb_opperation(list_t *list);
void rrr_opperation(list_t *list);

int decale_a_left(list_t *list);
int decale_b_left(list_t *list);
int decale_b_right(list_t *list);
int decale_a_right(list_t *list);

#endif
