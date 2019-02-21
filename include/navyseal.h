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

int sigbit;

typedef struct vector {
    int x;
    int y;
} vector_t;

/*
**  SIGNALS
*/
void siginit(void);
void handler(int sig);
int send_package(int pid, int bits, int dec);
int send_bit(int pid, int value);
int receive_package(int bits);
int receive_bit(void);
int init_connection(int his_pid);

/*
**  ERROR HANDLING
*/
int initial_err_check(int argc, const char **argv);

/*
**  GAME
*/
void render_navy(char **my_board, char **enemy_board);
void render_board(char *title, char **board);
void fill_board(char **board, int side, char c);
char **init_board(int side);
void *destroy_board(char **board, int side);
char **parse_file(char const *filename);
int read_boat(int fd, char *boat);
int add_boat(char **board, char *boat);
vector_t player_attack(char **his_board);
int check_lose(char **my_board);
int gameloop(char **my_board, char**his_board, int his_pid, int turn);
int check_hit(char **my_board, char **his_board, vector_t target);

#endif /* !NAVYSEAL_H_ */