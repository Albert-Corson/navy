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
    if (his_pid != 0) {
        send_package(his_pid, 17, getpid());
    } else {
        my_putstr("\nwaiting for enemy connection...\n\n");
        his_pid = receive_package(17);
        my_putstr("enemy connected\n");
    }
    return (his_pid);
}