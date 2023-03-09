/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** dsk
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int my_flag(char c, va_list ap)
{
    int(*flag[])(va_list) = {&flag_i, &flag_d, &flag_s, &flag_c, &flag_u ,
    &flag_o, &flag_pourcent, &flag_x, &flag_xx, &flag_f, &flag_e, &flag_ee,
    &flag_p, &flag_b};
    char *flags = "idscuo%xXfeEpb";

    int i = 0;
    while (flags[i] != 0) {
        if (flags[i] == c)
            flag[i](ap);
        i++;
    }
    return 0;
}

int espace(const char *typ_flag, int i)
{
    if (typ_flag[i] == ' ') {
        while (typ_flag[i] == ' ') {
            i++;
        }
        my_putchar(' ');
    }
    return i;
}

int plus(const char *typ_flag, int i, va_list ap)
{
    if (typ_flag[i] == '+'){
        while (typ_flag[i] == '+') {
            i++;
        }
        my_putchar('+');
    }
    return i;
}

int my_printf(const char *typ_flag , ...)
{
    va_list ap;
    int i = 0;
    int count = 0;
    va_start(ap, typ_flag);

    for (i;typ_flag[i] != '\0';i++) {
        if (typ_flag[i] == '%') {
            i++;
            i = plus(typ_flag, i, ap);
            i = espace(typ_flag, i);
            my_flag (typ_flag[i], ap);
        } else {
            my_putchar(typ_flag[i]);
            count++;
        }
    }
    va_end(ap);
}
