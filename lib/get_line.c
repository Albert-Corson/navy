/*
** EPITECH PROJECT, 2019
** navy
** File description:
** get_line
*/

#include "navyseal.h"

char *get_line(int fd)
{
    char *rtn = NULL;
    char buff = 0;
    int check = 0;

    if (fd < 0)
        return (NULL);
    check = read(fd, &buff, 1);
    while (check > 0) {
        if (buff != '\n') {
            rtn = my_copycat(rtn, &buff, 1);
            check = read(fd, &buff, 1);
        } else {
            rtn = my_copycat(rtn, "\0", 1);
            check = 0;
        }
    }
    return (rtn);
}