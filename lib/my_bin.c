/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** my_bin
*/

#include "my.h"

bin_t *dectobin(int dec)
{
    bin_t *bin = my_calloc(32, sizeof(short));
    int bits = 0;
    int order = 0;

    while (dec >> bits)
        ++bits;
    order = 32 - bits;
    while (bits - 1 >= 0) {
        bin[order] = ((dec & (1 << (bits - 1))) > 0);
        ++order;
        --bits;
    }
    return (bin);
}

int bintodec(bin_t *bin)
{
    int dec = 0;
    int bitsize = 1;
    int order = 31;

    while (order > 0) {
        dec += bitsize * bin[order];
        bitsize *= 2;
        --order;
    }
    return (dec);
}