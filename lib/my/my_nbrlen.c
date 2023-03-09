/*
** EPITECH PROJECT, 2022
** my_nbrlen
** File description:
** compter nombre de chiffre dans un nombre
*/

int my_nbrlen (int nb)
{
    int i = 0;
    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return (i);
}
