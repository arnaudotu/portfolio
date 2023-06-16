/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell1-safwane.mkhinini
** File description:
** set_unset
*/

#include "includes.h"

void remove_node (global_t *global, char *arg)
{
    char *str = malloc(sizeof(char) * my_strlen(arg) + 2);
    char *cop_str = my_strcpy(str, arg);
    (void) cop_str;
    char *cat_str = my_strcat(str, "=");
    node_t *temp = global->head;
    if (my_strncmp(temp->data, cat_str, my_strlen(cat_str)) == 0) {
        global->head = temp->next;
        free(temp->data);
        free (temp);
        return;
    }
    for (; temp->next != NULL; temp = temp->next) {
        if (my_strncmp(temp->next->data, cat_str, my_strlen(cat_str)) == 0) {
            node_t *remove = temp->next;
            temp->next = remove->next;
            free (remove->data);
            free (remove);
            return;
        }
    }
}

void add_name (global_t *global, char *arg)
{
    char *str = malloc(sizeof(char) * my_strlen(arg) + 2);
    char *cop_str = my_strcpy(str, arg);
    if (error_case(cop_str) == 1) {
        print_error();
        return;
    }
    if (alpha_case(cop_str) == 1) {
        print_error_alpha();
        return;
    }
    char *cat_str = my_strcat(str, "=");
    node_t *temp = global->head;
    for (; temp != NULL; temp = temp->next) {
        if (my_strncmp(temp->data, cat_str, my_strlen(cat_str)) == 0) {
            temp->data = cat_str;
            return;
        }
    }
    pushback(&global->head, cat_str);
    return;
}

void add_node (global_t *global, char **arg, int i)
{
    char *str = malloc(sizeof(char) * my_strlen(arg[i]) + 2);
    char *cop_str = my_strcpy(str, arg[1]);
    if (error_case(cop_str) == 1) {
        print_error(); return;
    }
    if (alpha_case(cop_str) == 1) {
        print_error_alpha(); return;
    }
    char *cat_str = my_strcat(str, "=");
    node_t *temp = global->head;
    for (; temp != NULL; temp = temp->next) {
        if (my_strncmp(temp->data, cat_str, my_strlen(cat_str)) == 0) {
            char *cat_str2 = my_strcat(cat_str, arg[1 + 1]);
            temp->data = cat_str2;
            return;
        }
    }
    char *cat_str2 = my_strcat(cat_str, arg[1 + 1]);
    pushback(&global->head, cat_str2);
    return;
}
