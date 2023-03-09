/*
** EPITECH PROJECT, 2022
** my_put_address
** File description:
** dsk
*/

#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"

void part2 (long long nbr)
{
    int size;
    long long nb;
    char *base = "0123456789abcdef";
    size = my_strlen(base);
    if (nbr > 0) {
        nb = nbr;
        nbr /= size;
        part2(nbr);
        my_putchar(base[nb % size]);
    }
}

int my_put_address(long long *nbr)
{
    if ((void *)nbr == NULL)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        part2((long long)nbr);
    }
    return (0);
}
