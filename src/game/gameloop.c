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
    if (hit == 84)
        return (84);
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

    send_package(his_pid, 4, target.x != -1 ? target.x : 9);
    send_package(his_pid, 4, target.y != -1 ? target.y : 9);
    RETURN_IF(target.x == -1, 84);
    RETURN_IF(kill(his_pid, 0) == -1, my_puterror("Connection lost\n"));
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

    my_putstr("waiting for enemy's attack...\n");
    target.x = receive_package(4);
    target.y = receive_package(4);
    RETURN_IF(target.x == 9, my_puterror("Connection lost\n"));
    hit = check_hit(my_board, target);
    send_package(his_pid, 2, hit);
    show_turn_result(target, hit);
    return (hit);
}

int gameloop(char **my_board, char **his_board, vector_t vect, int turn)
{
    int rtn = 1;
    int hit = 0;
    int his_pid = vect.x;
    int is_host = vect.y;

    RETURN_IF(kill(his_pid, 0) == -1, my_puterror("Connection lost\n"));
    if (is_host && turn)
        render_navy(my_board, his_board);
    if (turn) {
        hit = send_attack(his_board, his_pid);
        RETURN_IF(hit == 84, 84);
    } else
        hit = receive_attack(my_board, his_pid);
    if (!is_host && turn && hit != 84)
        render_navy(my_board, his_board);
    rtn = end_game(hit, turn);
    if (rtn == -1)
        return (gameloop(my_board, his_board, vect, !turn));
    return (rtn);
}