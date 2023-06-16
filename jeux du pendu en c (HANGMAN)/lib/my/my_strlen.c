/*
** EPITECH PROJECT, 2022
** task04
** File description:
** my_strlen
*/


void my_putchar(char c);

int my_strlen(char const *str)
{
    int chaine = 0;
    while (str[chaine] != '\0')
        chaine++;
    return (chaine);
}
