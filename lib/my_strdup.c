/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *src)
{
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest[0] = 0;
    my_strcpy(dest, src);
    return (dest);
}
