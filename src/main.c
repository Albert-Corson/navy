/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "navyseal.h"
#include <stdio.h>

void showbits(unsigned int x);

void showbits(unsigned int x)
{
    for(int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       (x & (1u << i)) ? my_putchar('1') : my_putchar(' ');
    }
    my_putchar('\n');
}

int main(int argc, char const *argv[])
{
    int rtn = 0;
    char **my_board = NULL;
    char **his_board = NULL;
    int pid = initial_err_check(argc, argv);

    RETURN_IF(pid < 0, 84);
    my_board = parse_file(argv[1]);
    RETURN_IF(!my_board, my_puterror("Invalid boat positions\n"));
    his_board = init_board(8);
    RETURN_IF(!his_board, 84);
    // rtn = game();
    render_navy(my_board, his_board);
    destroy_board(my_board, 8);
    return (rtn);
}