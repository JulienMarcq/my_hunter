/*
** EPITECH PROJECT, 2022
** myswap
** File description:
** dsk
*/

#include "../../include/my.h"

int my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
