/*
** EPITECH PROJECT, 2022
** my_size_file
** File description:
** dsk
*/

#include "../../include/my.h"

int my_size_file(char *av)
{
    int fd = open(av, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100000);
    int size = read(fd, buffer, 100000);

    free(buffer);
    return (size);
}
