/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_tablecpy
*/

#include "my.h"

char **my_tablendup(char **table, int lim, int to_malloc)
{
    int len = 0;
    int i = 0;
    char **cpy = NULL;

    if (!table)
        return (NULL);
    while (table[len] && (len < lim || lim == -1))
        ++len;
    if (to_malloc > 0)
        len = to_malloc;
    cpy = malloc(sizeof(char *) * (len + 1));
    while (i < len) {
        cpy[i] = my_strdup(table[i]);
        ++i;
    }
    cpy[i] = NULL;
    return (cpy);
}