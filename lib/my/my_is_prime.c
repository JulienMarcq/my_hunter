/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** dsk
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    while (i < nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
