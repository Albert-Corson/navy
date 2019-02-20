/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "navyseal.h"
#include <stdio.h>

void show_nodes(boat_t *boats)
{
    while (boats) {
        printf("L = %d | X = %d | Y = %d | Hor = %d\n", boats->length, boats->x, boats->y, boats->hor);
        boats = boats->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    int rtn = 0;
    boat_t *boats = NULL;
    char **map = NULL;
    int pid = initial_err_check(argc, argv);

    if (pid < 0)
        return (84);
    boats = get_boats(argv[argc - 1]);
    show_nodes(boats);
    // map = init_map(boats); Si boats est NULL init_map() devrait retrun NULL
    if (!map)
        return (84);
    // rtn = game();
    free_boats(boats);
    free_table(map);
    return (rtn);
}