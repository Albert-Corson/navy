/*
** EPITECH PROJECT, 2019
** navy
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

#include <stdlib.h>
#include <unistd.h>

int my_puterror(char const *str);
char *my_copycat(char *dest, char *src, int lim);
int get_char_pos(char const *str, char goal);
unsigned long long my_strlen(char const *str);
unsigned long long my_putstr(char const *str);
char *my_strdup(char *src);
int my_memcmp(void *m1, void *m2, long n);
int my_putchar(char c);
char *my_strcpy(char *dest, char *src);
long long my_getnbr(char const *str);
char **my_tablendup(char **table, int lim, int to_malloc);
unsigned long long my_put_err_nbr(signed long long int nb);
int my_putchar_err(char c);
int my_nisnum(char const *str, int lim);

#endif /* !LIB_H_ */