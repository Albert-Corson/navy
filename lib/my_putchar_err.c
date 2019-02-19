/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_putchar
*/

#include "my.h"

int my_putchar_err(char c)
{
    write(2, &c, 1);
    return (1);
}