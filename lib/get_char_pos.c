/*
** EPITECH PROJECT, 2019
** libmy.a
** File description:
** get_char_pos
*/

#include "my.h"

int get_char_pos(char const *str, char goal)
{
    int n = 0;

    if (str == NULL)
        return (-1);
    while (str[n] != goal && str[n]) {
        ++n;
    }
    if (str[n] != goal)
        return (-1);
    return (n);
}