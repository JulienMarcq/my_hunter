/*
** EPITECH PROJECT, 2022
** my_put
** File description:
** dsk
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

void my_putchar(char n)
{
    write(1, &n, 1);
}

int  my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}

void my_put_float(double n)
{
    if (n < 0) {
        my_putchar('-');
        n = absolute_valor(n);
    }
    int part_int = n;
    int part_dec = 0;
    int i = 0;

    my_put_nbr(part_int);
    my_putchar('.');

    n = n - part_int + 0.0000005;
    while (i < 6) {
        n = n * 10;
        part_dec = n;
        my_put_nbr(part_dec);
        n = n - part_dec;
        i++;
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
