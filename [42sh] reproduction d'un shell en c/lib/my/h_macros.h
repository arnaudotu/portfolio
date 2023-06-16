/*
** EPITECH PROJECT, 2023
** lib
** File description:
** Some important defines macros (including function overwriting)
*/

#ifndef INCLUDED_LIB_DEFINES_H
    #define INCLUDED_LIB_DEFINES_H

    #include "includes.h"

    #define STR(obj) #obj
    #define POINTER(obj) &obj

    #define true 1
    #define false 0

    // ####################### Colors #######################

    #define MY_COLOR_RESET "\33[0m"
    #define MY_COLOR_GREY "\33[90m"
    #define MY_COLOR_BLINK "\33[5m"
    #define MY_COLOR_RED "\33[91m"
    #define MY_COLOR_GREEN "\33[92m"
    #define MY_COLOR_YELLOW "\33[93m"
    #define MY_COLOR_BLUE "\33[94m"

    // ####################### Structs #######################

    #define m_box _m_box *

    // ####################### Functions #######################

    #define my_debug(type, var) dev_my_debug(my_create_box(STR(var),\
        POINTER(var), STR(type)), __LINE__, __FILE__)
    #define my_debug_custom(type, var, func) dev_my_debug_custom(\
        my_create_box(STR(var), POINTER(var), STR(type)), __LINE__, __FILE__,\
            func)

#endif
