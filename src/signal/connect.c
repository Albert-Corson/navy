/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connect
*/

#include "navyseal.h"

int init_connection(int his_pid)
{
    siginit();
    my_putstr("my_pid: ");
    my_putnbr(getpid());
    my_putchar('\n');
    if (his_pid != 0) {
        send_package(his_pid, 17, getpid());
        my_putstr("successfully connected\n\n");
    } else {
        my_putstr("waiting for enemy connection...\n\n");
        his_pid = receive_package(17);
        my_putstr("enemy connected\n\n");
    }
    return (his_pid);
}