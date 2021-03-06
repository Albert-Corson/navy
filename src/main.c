/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include "navyseal.h"

int main(int argc, char const *argv[])
{
    int rtn = 0;
    char **my_board = NULL;
    char **his_board = NULL;
    int his_pid = initial_err_check(argc, argv);

    RETURN_IF(his_pid < 0, 84);
    my_board = parse_file(argc == 2 ? argv[1] : argv[2]);
    RETURN_IF(!my_board, my_puterror("Invalid boat positions\n"));
    his_board = init_board(8);
    RETURN_IF(!his_board, 84);
    his_pid = init_connection(his_pid);
    if (argc == 3)
        render_navy(my_board, his_board);
    rtn = gameloop(my_board, his_board, VECTOR(his_pid, argc == 2), argc == 2);
    destroy_board(my_board, 8);
    return (rtn);
}