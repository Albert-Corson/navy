/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** boardgen
*/

#include "navyseal.h"

void fill_board(char **board, int side, char c)
{
    int index = 0;

    while (index < side) {
        board[index] = malloc(sizeof(char) * (side + 1));
        my_memset(board[index], c, side);
        board[index][side] = 0;
        ++index;
    }
    board[side] = NULL;
}

char **init_board(int side)
{
    char **board = malloc(sizeof(char *) * (side + 1));

    RETURN_IF(!board, NULL);
    fill_board(board, side, '.');
    return (board);
}

void *destroy_board(char **board, int side)
{
    int index = 0;

    while (index < side) {
        free(board[index]);
        ++index;
    }
    free(board);
    return (NULL);
}