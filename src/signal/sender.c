/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** sender
*/

#include "navyseal.h"

int send_package(int pid, int bits, int dec)
{
    bin_t *bin = dectobin(dec);
    while (bits - 1 >= 0) {
        usleep(3000);
        send_bit(pid, bin[32 - bits]);
        --bits;
    }
    free(bin);
    return (dec);
}

int send_bit(int pid, int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    return (!(bit == 0));
}