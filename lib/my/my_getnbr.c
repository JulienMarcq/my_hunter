/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** dsk
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int d = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            d = d * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i++;
    }
    nb = nb * d;
    return (nb);
}
