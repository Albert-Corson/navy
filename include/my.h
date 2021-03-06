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

typedef short bin_t;

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
char *get_line(int fd);
long my_put_nbr(signed long long nb);
char *get_input(void);
void my_putnbr(int nb);
void *my_memset(void *s, int c, size_t n);
void *my_calloc(size_t nmemb, size_t size);
bin_t *dectobin(int dec);
int bintodec(bin_t *bin);
long long my_pow(int x, int y);

#endif /* !LIB_H_ */