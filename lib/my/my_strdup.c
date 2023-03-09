/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** dsk
*/

#include "../../include/my.h"

char *my_strdup (char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return (NULL);
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
    free(dest);
}
