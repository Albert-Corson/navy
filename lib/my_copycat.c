/*
** EPITECH PROJECT, 2019
** libmy.a
** File description:
** my_copycat
*/

#include "my.h"

char *my_copycat(char *dest, char *src, int lim)
{
    char *rtn;
    int n = 0;
    int tmp = 0;

    lim = lim == -1 ? get_char_pos(src, 0) : lim;
    if (dest == NULL)
        rtn = malloc(sizeof(char) * (lim + 1));
    else {
        rtn = malloc(sizeof(char) * (get_char_pos(dest, 0) + lim + 1));
        while (dest[n] != 0) {
            rtn[n] = dest[n];
            ++n;
        }
        free(dest);
    }
    while (src[tmp] != 0 && tmp < lim) {
        rtn[tmp + n] = src[tmp];
        ++tmp;
    }
    rtn[tmp + n] = 0;
    return (rtn);
}