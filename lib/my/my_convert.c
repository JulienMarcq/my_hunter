/*
** EPITECH PROJECT, 2022
** my_convert
** File description:
** dsk
*/

#include "../../include/my.h"

int absolute_valor(int n)
{
    if (n < 0) {
        n = n * -1;
    }
    return (n);
}

void my_hexadecimal_convertmin(int decNum)
{

    char hexaDeciNum[50];
    int i = 0;
    while (decNum != 0) {
        hexaDeciNum[i] = (char)(*("0123456789abcdef"+ ((decNum % 16) & (15))));
        decNum = (decNum / 16);
        ++i;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(hexaDeciNum[j]);
    }
}

void my_hexadecimal_convertmaj(int decNum)
{

    char hexaDeciNum[50];
    int i = 0;
    while (decNum != 0) {
        hexaDeciNum[i] = (char)(*("0123456789ABCDEF"+ ((decNum % 16) & (15))));
        decNum = (decNum / 16);
        ++i;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(hexaDeciNum[j]);
    }
}

int my_octal_converter(int nb)
{
    int i = 1;
    int octal = 0;

    while (nb != 0) {
        octal += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    return (octal);
}

int my_binary_converter(unsigned int nb)
{
    int i = 1;
    int bin = 0;

    while (nb != 0) {
        bin += (nb % 2)*i;
        nb /= 2;
        i *= 10;
    }
    my_put_nbr(bin);
    return (0);
}
