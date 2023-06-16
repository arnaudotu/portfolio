/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** eturns the first argument raised to the power p,
** where p is the second argument.
*/

int my_compute_power_it ( int nb , int p )
{
    if (p < 0) {
        return (0);
        }
    if (p == 0) {
        return (1);
    }
    int result = nb;
    for (int i = 1; i < p;i++){
        result = result * nb;
    }
    return (result);
}
