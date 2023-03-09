/*
** EPITECH PROJECT, 2022
** flag
** File description:
** dsk
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int flag_i (va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

int flag_d (va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

int flag_s (va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

int flag_c (va_list ap)
{
    my_putchar(va_arg(ap, int));
}

int flag_u (va_list ap)
{
    my_put_nbr(va_arg(ap, unsigned int));
}
