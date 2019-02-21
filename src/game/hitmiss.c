/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** hitmiss
*/

#include "navyseal.h"

int check_lose(char **my_board)
{
    vector_t index = VECTOR(0, 0);
    char tile = 0;

    while (index.y < 8) {
        index.x = 0;
        tile = my_board[index.y][index.x];
        while (index.x < 8 && get_char_pos("2345", tile) == -1) {
            tile = my_board[index.y][index.x];
            ++index.x;
        }
        if (index.x < 8)
            return (0);
        ++index.y;
    }
    return (1);
}