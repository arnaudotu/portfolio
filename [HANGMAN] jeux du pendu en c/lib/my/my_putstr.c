/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_putstr
*/


void my_putchar(char c);

int my_putstr (char const *str)
{
    int chaine = 0;
    while (str[chaine] != '\0'){
        my_putchar(str[chaine]);
        chaine++;
    }
}
