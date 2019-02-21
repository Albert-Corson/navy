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
#define RETURN_IF(cond, exit_status)  if (cond) return (exit_status);

#define VECTOR(x, y)    (vector_t){x, y}

typedef struct vector {
    int x;
    int y;
} vector_t;

void get_connected(int target);
int initial_err_check(int argc, const char **argv);

void render_navy(char **my_board, char **enemy_board);
void render_board(char *title, char **board);
void fill_board(char **board, int side, char c);
char **init_board(int side);
void *destroy_board(char **board, int side);
char **parse_file(char const *filename);
int read_boat(int fd, char *boat);
int add_boat(char **board, char *boat);
vector_t player_attack(char **his_board);

#endif /* !NAVYSEAL_H_ */