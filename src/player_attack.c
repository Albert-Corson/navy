/*
** EPITECH PROJECT, 2019
** navy
** File description:
** player_attack
*/

#include "navyseal.h"

int check_input(char *input)
{
    int x = 0;
    int y = 0;

    if (input && my_strlen(input) != 2)
        return (0);
    if (!input)
        return (1);
    x = input[0] - 65;
    y = input[1] - 49;
    if (x < 0 || x > 8 || y < 0 || y > 8)
        return (0);
    return (1);
}

vector_t player_attack(void)
{
    char *input = NULL;
    vector_t attack = VECTOR(-1, -1);

    my_putstr("attack: ");
    input = get_input();
    while (!check_input(input)) {
        free(input);
        my_putstr("wrong position\n");        
        my_putstr("attack: ");
        input = get_input();
    }
    if (!input) {
        free(input);
        return (attack);
    }
    attack = VECTOR(input[0] - 65, input[1] - 49); 
    free(input);
    return (attack);
}