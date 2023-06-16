/*
** EPITECH PROJECT, 2022
** task01
** File description:
** my_strncpy.c
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;
    for (; src[j] != '\0' ; j++) {
        dest[j + i] = src[j];
    }
    dest[j + i] = '\0';
    return dest;
}
