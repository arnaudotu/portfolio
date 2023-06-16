/*
** EPITECH PROJECT, 2023
** main
** File description:
** project
*/

#ifndef INCLUDED_PROJECT_H
    #define INCLUDED_PROJECT_H

    #include "includes.h"

    #define BLUE "\e[1;36m"
    #define RED "\e[1;31m"
    #define WHITE "\e[0;00m"
    #define PROMPT RED"[~"BLUE"42sh"RED"~]"BLUE" $> "WHITE

    #define true 1
    #define false 0

typedef struct node_s {
    char *data;
    struct node_s *next;
}node_t;

typedef struct global_s {
    void (*check_tab[6])(struct global_s *global, char **arg);
    char *command[7];
    node_t *head;
    node_t *head_red_left;
    char **env;
    char *buffer;
    char *buffer_redi;
    int redirection;
    int file;
    int output;
} global_t;

/// BUILT_IN COMMAND
    void env_command (global_t *global, char **arg);
    void exit_command (global_t *global, char **arg);
    void unsetenv_command(global_t *global, char **arg);
    void remove_node (global_t *global, char *arg);
    void setenv_command (global_t *global, char **arg);
    void cd_command (global_t *global, char** arg);
    void add_node (global_t *global, char **arg, int i);
    void add_name (global_t *global, char *arg);
    void cd_basic (global_t *global);
    void cd_err (char *arg);
    void cd_dash (global_t *global);
    void cd_dcommand (global_t *global);
    void check_empty (global_t *global);
    void check_cond (global_t *global, char *arg);
    void if_cond (int search, char *arg);
    char *recup_pwd (void);
/// BUILT_IN COMMAND

/// ERROR_CASE
    int error_case (char *arg);
    int alpha_case (char *arg);
    void print_error_alpha (void);
    void print_error (void);
    void comm_error (global_t *global);
    void signal_error (int status);
    void execve_error (char *arg, int val);
/// ERROR_CASE

/// SPLIT_STRING
    char **loop_strtok2 (char *str, char *delim);
    char **loop_strtok (char *str);
    int count_word (char *str, char *delim);
/// SPLIT_STRING

/// LINKED_LIST
    void pushback(node_t **head, char *new);
    void print_list (node_t *temp);
    void env_list (node_t **head, char **env);
    char **linked_transform (node_t *head);
/// LINKED_LIST

/// RECUP_PATH
    int check_path (char *path, char *cmd);
    char *path_recup (char **env, char **cmd);
    char *browse_loop (char *env, char **cmd);
    char *check_acess (char **arg);
    void choose_path (global_t *global, char **arg);
    int shell_start(char *buffer, global_t *global, int i);
/// RECUP_PATH

/// EXECVE_COMMAND
    void check_command (global_t *global, char **arg);
    int execve_abslte (global_t *global, char **arg);
    void check_smicolon (char **buffer, global_t *global);
/// EXECVE_COMMAND

/// REDIRECTION_COMMAND
    int redirection(char *buffer, global_t *global, int flag, char *separator);
    int what_redirection(char *buffer, global_t *global, int i);
    int what_redirection_bravo(char *buffer, global_t *global, int i);
    int redi_right(char *buffer, global_t *global, int flag, char *sep);
    int redi_left(char *buffer, global_t *global, int flag, char *sep);
    int double_redi_left(char *buffer, global_t *global, char *sep);
/// REDIRECTION_COMMAND

    int my_printf(char *format, ...);
#endif
