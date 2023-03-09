/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** dsk
*/

int my_compute_square_boot(int nb)
{
    int i = 1;
    int b = 0;

    while (b < nb) {
        b = i * i;
        if (b == nb) {
            return (i);
        }
        i = i + 1;
    }
    return (0);
}
