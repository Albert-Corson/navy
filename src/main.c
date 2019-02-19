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

int initial_err_check(int argc, const char **argv)
{
    int pid = 0;

    if (argc != 3 && argc != 2) {
        my_puterror("One or two arguments expected\n");
        return (-1);
    }
    if (argc == 3 && my_nisnum(argv[1], -1))
        pid = my_getnbr(argv[1]);
    if (pid <= 0 || kill(pid, 0) == -1) {
        my_puterror("Invalid PID\n");
        return (-1);
    }
    return (pid);
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