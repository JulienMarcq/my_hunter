/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** dsk
*/
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#ifndef LIBMYPRINTF
    #define LIBMYPRINTF
    int flag_i (va_list ap);
    int flag_d (va_list ap);
    int flag_s (va_list ap);
    int flag_c (va_list ap);
    int flag_u (va_list ap);
    int flag_o (va_list ap);
    int flag_x (va_list ap);
    int flag_xx (va_list ap);
    int flag_pourcent (va_list ap);
    int flag_f (va_list ap);
    int flag_e (va_list ap);
    int flag_ee (va_list ap);
    int flag_p (va_list ap);
    int flag_b (va_list ap);
    int my_printf(const char *typ_flag , ...);
    int my_put_nbr(int nb);
    int  my_putstr(char const *str);
    void my_putchar(char c);
    int my_octal_converter(int nb);
    void my_hexadecimal_convertmin(int decNum);
    void my_hexadecimal_convertmaj(int decNum);
    void my_put_float(double myfloat);
    int my_scientific_converter(double nb, int s);
    int my_strlen(char const *str);
    int my_put_address(long long *nbr);
    int my_binary_converter(unsigned int nb);
    int absolute_valor(int n);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_isneg(int n);
    int my_is_prime(int nb);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strstr(char *str, char *to_find);
    int my_swap(int *a, int *b);
    int my_nbrlen (int nb);
    char **my_str_to_word_array(char *str);
    char *my_strdup (char *src);
    int compt_line(char *str);
    int my_size_file(char *av);
    char *my_itoa (int number);
#endif /* !LIBMYPRINTF */
