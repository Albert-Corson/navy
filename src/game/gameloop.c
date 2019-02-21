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
    my_putstr(": ");
    if (hit)
        my_putstr("hit\n\n");
    else
        my_putstr("missed\n\n");
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
    return (-1);
}

int send_attack(char **his_board, int his_pid)
{
    vector_t target = player_attack(his_board);
    int hit = 0;

    send_package(his_pid, 3, target.x);
    send_package(his_pid, 3, target.y);
    RETURN_IF(kill(his_pid, 0) == -1, my_puterror("Enemy disconnected\n"));
    hit = receive_package(2);
    show_turn_result(target, hit);
    if (hit)
        his_board[target.y][target.x] = 'x';
    else
        his_board[target.y][target.x] = 'o';
    return (hit);
}

int receive_attack(char **my_board, int his_pid)
{
    vector_t target;
    int hit = 0;

    my_putstr("waiting for enemy’s attack...\n");
    target.x = receive_package(3);
    target.y = receive_package(3);
    hit = check_hit(my_board, target);
    send_package(his_pid, 2, hit);
    show_turn_result(target, hit);
    return (hit);
}

int gameloop(char **my_board, char **his_board, int his_pid, int turn)
{
    int rtn = 1;
    int hit = 0;

    RETURN_IF(kill(his_pid, 0) == -1, my_puterror("Enemy disconnected\n"));
    if (turn) {
        hit = send_attack(his_board, his_pid);
        RETURN_IF(hit == 84, 84);
    } else
        hit = receive_attack(my_board, his_pid);
    render_navy(my_board, his_board);
    rtn = end_game(hit, turn);
    if (rtn == -1)
        return (gameloop(my_board, his_board, his_pid, !turn));
    return (rtn);
}