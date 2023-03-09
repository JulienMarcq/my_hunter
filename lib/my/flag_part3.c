/*
** EPITECH PROJECT, 2022
** flag
** File description:
** dsk
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int flag_e (va_list ap)
{
    my_scientific_converter(va_arg(ap, double), 1);
}

int flag_ee (va_list ap)
{
    my_scientific_converter(va_arg(ap, double), 2);
}

int flag_p (va_list ap)
{
    my_put_address(va_arg(ap, long long *));
}

int flag_b (va_list ap)
{
    my_binary_converter(va_arg(ap, unsigned int));
}
