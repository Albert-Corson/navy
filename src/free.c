/*
** EPITECH PROJECT, 2019
** navy
** File description:
** free
*/

#include "navyseal.h"

void free_boats(boat_t *boats)
{
    boat_t *tmp = boats->next;

    while (tmp) {
        free(boats);
        boats = tmp;
        tmp = boats->next;
    }
    free(boats);
}