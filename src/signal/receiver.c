/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** receiver
*/

#include "navyseal.h"

int receive_package(int bits)
{
    bin_t *bin = my_calloc(32, sizeof(short));
    int order = 0;
    int dec = 0;

    while (dec >> bits)
        ++bits;
    order = 32 - bits;
    while (bits - 1 >= 0) {
        bin[order] = receive_bit();
        ++order;
        --bits;
    }
    dec = bintodec(bin);
    free(bin);
    return (dec);
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