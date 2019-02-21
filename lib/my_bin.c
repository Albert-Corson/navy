/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** my_bin
*/

#include "my.h"

unsigned long dectobin(int dec)
{
    unsigned long bin = 0;
    int bits = 0;
    unsigned long order = 0;

    while (dec >> bits)
        ++bits;
    order = my_pow(10, bits - 1);
    while (bits - 1 >= 0) {
        bin += order * ((dec & (1 << (bits - 1))) > 0);
        order /= 10;
        --bits;
    }
    return (bin);
}

int bintodec(unsigned long bin)
{
    int bits = 0;
    unsigned long tmp = bin;
    int dec = 0;
    unsigned long bitsize = 1;

    while (tmp > 0) {
        tmp /= 10;
        ++bits;
    }
    while (bits > 0) {
        dec += bitsize * (bin % 10);
        bin /= 10;
        bitsize *= 2;
        --bits;
    }
    return (dec);
}