/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** dsk
*/

#include <stdio.h>

int my_strcont(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int b = my_strcont(dest);

    while (src[i] != '\0') {
        dest[b + i] = src[i];
        i++;
    }
    dest[b + i] = '\0';
    return (dest);
}
