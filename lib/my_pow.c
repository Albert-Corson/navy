/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** my_pow
*/

#include "my.h"

long long my_pow(int x, int y)
{
    if (y == 0)
        return (1);
    else if (y < 0)
        return (0);
    return (x * my_pow(x, y - 1));
}