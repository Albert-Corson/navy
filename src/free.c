/*
** EPITECH PROJECT, 2019
** navy
** File description:
** free
*/

#include "navyseal.h"

void free_boats(boat_t *boats)
{
    if (!boats)
        return;
    boat_t *tmp = boats->next;

    while (tmp) {
        free(boats);
        boats = tmp;
        tmp = boats->next;
    }
    free(boats);
}

void *free_table(char **table)
{
    int i = 0;

    if (!table)
        return (NULL);
    while (table[i]) {
        free(table[i]);
        ++i;
    }
    free(table);
    return (NULL);
}