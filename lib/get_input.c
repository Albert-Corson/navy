/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** get_input
*/

#include "my.h"

char *get_input(void)
{
    int i = 0;
    char tmp = 0;
    char *rtn = malloc(sizeof(char));

    rtn[0] = 0;
    i = read(0, &tmp, 1);
    while (i > 0 && tmp != '\n') {
        rtn = my_copycat(rtn, &tmp, 1);
        i = read(0, &tmp, 1);
    }
    if (tmp != '\n') {
        free(rtn);
        return (NULL);
    }
    return (rtn);
}