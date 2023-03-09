/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** dsk
*/

int my_find_prime_sup(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
