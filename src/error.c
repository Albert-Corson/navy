/*
** EPITECH PROJECT, 2019
** navy
** File description:
** error
*/

#include "navyseal.h"

int initial_err_check(int argc, const char **argv)
{
    int pid = 0;

    if (argc == 2)
        return (0);
    if (argc != 3) {
        my_puterror("One or two arguments expected\n");
        return (-1);
    }
    if (my_nisnum(argv[1], -1))
        pid = my_getnbr(argv[1]);
    if (pid <= 0 || kill(pid, 0) == -1) {
        my_puterror("Invalid PID\n");
        return (-1);
    }
    return (pid);
}