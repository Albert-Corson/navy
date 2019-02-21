/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** receiver
*/

#include "navyseal.h"

int receive_package(int bits)
{
    int index = 0;
    unsigned long bin = 0;
    unsigned long order = my_pow(10, bits - 1);

    while (index < bits) {
        bin += order * receive_bit();
        order /= 10;
        ++index;
    }
    return (bintodec(bin));
}

int receive_bit(void)
{
    sigbit = -1;
    pause();
    if (sigbit == 0 || sigbit == 1)
        return (sigbit);
    else
        return (receive_bit());
}