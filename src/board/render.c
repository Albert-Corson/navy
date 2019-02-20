/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** render
*/

#include "navyseal.h"

void render_navy(char **my_board, char **enemy_board)
{
    render_board("my positions:", my_board);
    render_board("enemy's positions:", enemy_board);
}

void render_board(char *title, char **board)
{
    int row = 0;
    int col = 0;

    my_putstr(title);
    my_putchar('\n');
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    while (row < 8) {
        col = 0;
        my_putnbr(row + 1);
        my_putchar('|');
        while (col < 8) {
            my_putchar(board[row][col]);
            my_putchar(' ');
            ++col;
        }
        my_putchar('\n');
        ++row;
    }
    my_putstr("\n");
}