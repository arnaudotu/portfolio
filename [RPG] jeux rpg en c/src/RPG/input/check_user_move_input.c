/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file that contains the main function
*/

#include "../../../include/game.h"

sfBool check_arrow_input(void)
{
    if (!check_up_input()
        && !check_down_input()
        && !check_left_input()
        && !check_right_input()) {
            return (sfFalse);
    }
    return (sfTrue);
}

sfBool check_left_input(void)
{
    if (!sfKeyboard_isKeyPressed(sfKeyLeft)) {
            return (sfFalse);
    }
    return (sfTrue);
}

sfBool check_right_input(void)
{
    if (!sfKeyboard_isKeyPressed(sfKeyRight)) {
            return (sfFalse);
    }
    return (sfTrue);
}

sfBool check_up_input(void)
{
    if (!sfKeyboard_isKeyPressed(sfKeyUp)) {
            return (sfFalse);
    }
    return (sfTrue);
}

sfBool check_down_input(void)
{
    if (!sfKeyboard_isKeyPressed(sfKeyDown)) {
            return (sfFalse);
    }
    return (sfTrue);
}
