/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** handler
*/

#include "navyseal.h"

void handler(int sig)
{
    if (sig == SIGUSR1)
        sigbit = 0;
    if (sig == SIGUSR2)
        sigbit = 1;
}

void siginit(void)
{
    sigbit = 0;
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    sa.sa_flags = SA_NODEFER;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_puterror("Sign Error\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_puterror("Sign Error\n");
}