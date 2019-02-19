/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "navyseal.h"

int main(int argc, char const *argv[])
{
    int rtn = 0;
    boat_t *boats = NULL;
    char **map = NULL;
    int pid = 0;

    if ((argc != 3 && argc != 2) || (argc == 3 && !my_nisnum(argv[1], -1)))
        return (84);
    if (argc == 3)
        pid = my_getnbr(argv[1]);
    if (kill(pid, 0) == -1) {
        my_puterror("PID doesn't exist\n");
        return (84);
    }
    boats = get_boats(argv[argc - 1]);
    map = init_map(boats);
    return (rtn);
}