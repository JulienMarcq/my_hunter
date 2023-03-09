/*
** EPITECH PROJECT, 2022
** my_str_to_world_array
** File description:
** dsk
*/
#include <stdlib.h>
#include "../../include/my.h"

int compt_line(char *str)
{
    int i = 0, a = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            a++;
        i++;
    }
    return (a);
}

int compt_char(char *str, int line)
{
    int i = 0, a = 0;

    while (line != 0) {
        while (str[i] != '\n') {
            i++;
        }
        i++;
        line -= 1;
    }
    while (str[i] != '\n') {
        a++;
        i++;
        if (str[i] == '\0')
            break;
    }
    return (a);
}

char **my_str_to_word_array(char *str)
{
    int i = 0, b = 0;
    char **tab = malloc(sizeof(char *) * (compt_line(str)) + 1);
    for (int a = 0; a != compt_line(str); a++) {
        tab[a] = malloc(sizeof(char) * (compt_char(str, a)) + 1);
        for (b = 0; b != compt_char(str, a); b++) {
            tab[a][b] = str[i];
            i++;
        }
        if (str[i] == '\n')
            i++;
        tab[a][b] = '\0';
    }
    tab[compt_line(str)] = NULL;
    return (tab);
}
