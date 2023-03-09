/*
** EPITECH PROJECT, 2022
** my_scientific_venverter
** File description:
** dsk
*/
#include <stdarg.h>
#include "../../include/my.h"

int part2scien(int countinv, int count, int s)
{
    if (s == 1)
        my_putchar ('e');
    if (s == 2)
        my_putchar ('E');
    if (countinv != 0) {
        my_putchar('-');
        if (count < 10) {
            my_putchar('0');
        }
        my_put_nbr(countinv);
        return (0);
    } else {
        my_putchar('+');
        if (count < 10) {
            my_putchar('0');
        }
        my_put_nbr(count);
        return (0);
    }
}

int my_scientific_converter(double nb, int s)
{
    int i = 0, count = 0, countinv = 0;
    if (nb < 0){
        my_putchar('-');
        nb = absolute_valor(nb);
    } while (nb < 1) {
        nb = nb * 10;
        countinv++;
    } while (nb > 10) {
        nb = nb / 10;
        count++;
    } int part_int = nb, part_dec = 0;
    my_put_nbr(part_int);
    my_putchar('.');
    nb = nb- part_int + 0.0000005;
    while (i < 6) {
        part_dec = nb = nb * 10 ;
        my_put_nbr(part_dec);
        nb = nb - part_dec;
        i++;
    } part2scien(countinv, count, s);
}
