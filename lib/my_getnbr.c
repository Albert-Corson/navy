/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

long long my_getnbr(char const *str)
{
    long long nbr = 0;
    int n = 0;

    while (str[n] == ' ' || str[n] == '-' || str[n] == '+')
        ++n;
    while (n < (int)my_strlen(str)) {
        if (str[n] <= 57 && str[n] >= 48)
            nbr = nbr * 10 + str[n] - 48;
        if (str[n] > 57 || str[n] < 48)
            n = (int)my_strlen(str);
        if (nbr < 0)
            return (0);
        ++n;
    }
    n = 0;
    while (str[n] == ' ' || str[n] == '-' || str[n] == '+') {
        if (str[n] == '-')
            nbr *= -1;
        ++n;
    }
    return (nbr);
}