/*
** EPITECH PROJECT, 2019
** navy
** File description:
** get_boats
*/

#include "navyseal.h"

boat_t *err_msg(char const *file, int i, int fd, boat_t *boats)
{
    if (i < 0 || fd < 0) {
        my_puterror(file);
        if (i < 0)
            my_puterror(": Sythax error or wrong ship format\n");
        else
            my_puterror(": Cannot open such file\n");
        free_boats(boats);
        return (NULL);
    }
    return (boats);
}

int check_alignement(char *line, boat_t *new)
{
    int x = line[5] - 65;
    int y = line[6] - 49;

    if (x < 0 || x > 7 || y < 0 || y > 7)
        return (-1);
    if (x == new->x) {
        if (ABS(y - new->y) == new->length - 1)
            return (1);
    }
    if (y == new->y) {
        if (ABS(x - new->x) == new->length - 1)
            return (0);
    }
    return (-1);
}

boat_t *init_boat(boat_t *next)
{
    boat_t *new = malloc(sizeof(*new));

    new->length = -1;
    new->hor = -1;
    new->x = -1;
    new->y = -1;
    new->next = next;
    return (new);
}

boat_t *add_boat(char *line, boat_t *next_node)
{
    boat_t *new = NULL;
    int tmp = 0;

    if (line[1] != ':' || line[4] != ':')
        return (NULL);
    new = init_boat(next_node);
    if (my_nisnum(line, 1))
        new->length = line[0] - 48;
    tmp = line[2] - 65;
    if (tmp >= 0 && tmp < 8)
        new->x = tmp;
    tmp = line[3] - 49;
    if (tmp >= 0 && tmp <= 8)
        new->y = tmp;
    new->hor = check_alignement(line, new);
    if (new->length == -1 || new->hor == -1 || new->x == -1 || new->y == -1) {
        free(new);
        return (NULL);
    }
    return (new);
}

boat_t *get_boats(char const *file)
{
    boat_t *boats = NULL;
    boat_t *tmp = NULL;
    int i = 0;
    int fd = open(file, O_RDONLY);
    char *line = get_line(fd);

    while (fd >= 0 && line && i >= 0) {
        if (my_strlen(line) != 7 || i > 4)
            i = -2;
        tmp = i >= 0 ? add_boat(line, boats) : NULL;
        if (!tmp)
            i = -2;
        else
            boats = tmp;
        free(line);
        line = get_line(fd);
        ++i;
    }
    return (err_msg(file, i, fd, boats));
}