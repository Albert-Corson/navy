/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** task03
*/

#include "my.h"

unsigned long long my_strlen(char const *str)
{
    unsigned long long n = 0;

    if (str == NULL)
        return (0);
    while (str[n])
        ++n;
    return (n);
}
