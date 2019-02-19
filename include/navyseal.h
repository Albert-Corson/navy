/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navyseal
*/

#ifndef NAVYSEAL_H_
    #define NAVYSEAL_H_

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include "my.h"

#define ABS(x) (x < 0 ? -x : x)

typedef struct boat {
    int length;
    int y;
    int x;
    int hor;
    struct boat *next;
} boat_t;

void free_boats(boat_t *boats);
void *free_table(char **table);
boat_t *get_boats(char const *file);

#endif /* !NAVYSEAL_H_ */