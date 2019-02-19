/*
** EPITECH PROJECT, 2019
** navy
** File description:
** get_boats
*/

#include "navyseal.h"

boat_t *get_boats(char *file)
{
    int check[5] = {0};
    int fd = open(file, O_RDONLY);

    while (fd != -1 && check[0] < 5) {
    }
}