/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connect
*/

#include "navyseal.h"

void get_connected(int target)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    if (target != 0) {
        my_putstr("\nGOTTA CONNECT\n");
    } else {
        my_putstr("\nwaiting for enemy connection...\n\n");
    }
}