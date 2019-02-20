/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Task07
*/

#include "my.h"

long my_put_nbr(signed long long nb)
{
    long nb_len = 1;

    if (nb < 10 && nb > -10) {
        if (nb < 0) {
            my_putchar(45);
            ++nb_len;
            my_putchar((nb * -1) + 48);
        } else
            my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar('-');
        ++nb_len;
        nb_len += my_put_nbr((nb / 10) * -1);
        my_putchar(((nb % 10) * -1) + '0');
    } else {
        if (nb >= 10) {
            nb_len += my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) + '0');
    }
    return (nb_len);
}