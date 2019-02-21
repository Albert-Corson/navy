/*
** EPITECH PROJECT, 2019
** navy
** File description:
** gameloop
*/

#include "navyseal.h"

void show_turn_result(vector_t target, int hit)
{
    my_putchar(target.x + 65);
    my_putchar(target.y + 49);
    my_putchar(': ');
    if (hit)
        my_putstr("hit\n\n");
    else
        my_putstr("missed\n\n");
}

int check_hit(char **my_board, vector_t target)
{
    char impact = my_board[target.y][target.x];

    if (check_lose(my_board))
        return (2);
    if (get_char_pos("2345", impact) >= 0) {
        my_board[target.y][target.x] = 'x';
        return (1);
    } else {
        my_board[target.y][target.x] = 'o';
        return (0);
    }
}

int end_game(int hit, int turn)
{
    if (turn && hit == 2) {
        my_putstr("I won\n");
        return (0);
    } else if (!turn && hit == 2) {
        my_putstr("Enemy won\n");
        return (1);
    }
    return (-1)
}

int gameloop(char **my_board, char**his_board, int his_pid, int turn)
{
    int rtn = 1;
    int hit = 0;
    vector_t target = VECTOR(-1, -1);

    if (turn) {
        target = player_attack(his_board);
        send_package(his_board, 3, target.x);
        send_package(his_board, 3, target.y);
        hit = receive_package(2);
    } else {
        target.x = receive_package(3);
        target.y = receive_package(3);
        hit = check_hit(my_board, target);
        send_package(his_pid, 2, hit);
    }
    show_turn_result(target, hit);
    render_navy(my_board, his_board);
    rtn = end_game(hit, turn);
    if (rtn == -1);
        return (gameloop(my_board, his_board, his_pid, !turn));
    return (rtn);
}