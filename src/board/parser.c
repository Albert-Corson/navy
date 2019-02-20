/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** parser
*/

#include "navyseal.h"

int add_boat(char **board, char *boat)
{
    vector_t head = VECTOR(boat[2] - 65, boat[3] - 48 - 1);
    vector_t tail = VECTOR(boat[5] - 65, boat[6] - 48 - 1);
    vector_t speed = VECTOR(0, 0);
    int size = boat[0] - 48;

    speed.x = tail.x != head.x ? (tail.x - head.x) / ABS(tail.x - head.x) : 0;
    speed.y = tail.y != head.y ? (tail.y - head.y) / ABS(tail.y - head.y) : 0;
    RETURN_IF(head.x != tail.x && head.y != tail.y, 1);
    RETURN_IF(speed.x == 0 && ABS(tail.y - head.y) + 1 != size, 1);
    RETURN_IF(speed.y == 0 && ABS(tail.x - head.x) + 1 != size, 1);
    while (head.x - speed.x != tail.x || head.y - speed.y != tail.y) {
        RETURN_IF(board[head.y][head.x] != '.', 1);
        board[head.y][head.x] = size + 48;
        head.x += speed.x;
        head.y += speed.y;
    }
    return (0);
}

int read_boat(int fd, char *boat)
{
    int readsize = 0;
    int checks = 0;
    
    my_memset(boat, 0, 8);
    readsize = read(fd, boat, 8);
    RETURN_IF(readsize < 7, 1);
    checks += boat[0] >= '1' && boat[0] <= '8';
    checks += boat[1] == ':';
    checks += boat[2] >= 'A' && boat[2] <= 'H';
    checks += boat[3] >= '1' && boat[3] <= '8';
    checks += boat[4] == ':';
    checks += boat[5] >= 'A' && boat[5] <= 'H';
    checks += boat[6] >= '1' && boat[6] <= '8';
    checks += boat[7] == '\n' || boat[7] == '\0';
    return (checks != 8);
}

char **parse_file(char const *filename)
{
    char **board = init_board(8);
    int sizes[4] = {0, 0, 0, 0};
    int fd = open(filename, O_RDONLY);
    char boat[9];
    int index = 0;
    int err = 0;

    RETURN_IF(!board, NULL);
    RETURN_IF(fd == -1, destroy_board(board, 8));
    while (index < 4) {
        err = read_boat(fd, boat);
        RETURN_IF(err || sizes[boat[0] - 48 - 2], destroy_board(board, 8));
        sizes[boat[0] - 48 - 2] = 1;
        err = add_boat(board, boat);
        RETURN_IF(err, destroy_board(board, 8));
        ++index;
    }
    RETURN_IF(boat[7] != '\0', destroy_board(board, 8));
    return (board);
}