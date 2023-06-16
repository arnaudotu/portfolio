/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-minishell1-safwane.mkhinini
** File description:
** linked
*/

#include "includes.h"

void pushback(node_t **head, char *new)
{
    if (*head == NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = my_strdup(new);
        new_node->next = *head;
        *head = new_node;
    } else {
        node_t *temp = *head;
        for (;temp->next != NULL; temp = temp->next);
        node_t *new_node = malloc(sizeof(node_t));
        temp->next = new_node;
        new_node->data = my_strdup (new);
        new_node->next = NULL;
    }
}

void env_list (node_t **head, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        pushback(head, env[i]);
    }
}

void print_list (node_t *head)
{
    while (head != NULL) {
        my_printf("%s\n", head->data);
        head = head->next;
    }
}

char **linked_transform (node_t *head)
{
    int count_size = 0; int word = 0;
    for (node_t *temp = head; temp != NULL; temp = temp->next) {
        count_size++;
    }
    char **arr = malloc(sizeof(char *) * (count_size + 1));
    arr[count_size] = NULL;
    for (node_t *temp = head; temp != NULL; temp = temp->next, word++) {
        arr[word] = my_strdup(temp->data);
    }
    return (arr);
}
