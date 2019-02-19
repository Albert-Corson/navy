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

typedef struct boat {
    int length;
    int y;
    int x;
    int hor;
    struct boat *next;
} boat_t;

#endif /* !NAVYSEAL_H_ */