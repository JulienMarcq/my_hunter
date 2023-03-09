/*
** EPITECH PROJECT, 2022
** flag
** File description:
** dsk
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int flag_o (va_list ap)
{
    my_put_nbr(my_octal_converter(va_arg(ap, int)));
}

int flag_pourcent (va_list ap)
{
    my_putchar('%');
}

int flag_x (va_list ap)
{
    my_hexadecimal_convertmin(va_arg(ap, int));
}

int flag_xx (va_list ap)
{
    my_hexadecimal_convertmaj(va_arg(ap, int));
}

int flag_f (va_list ap)
{
    my_put_float(va_arg(ap, double));
}
