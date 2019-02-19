/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Copy a string into another
*/

char *my_strcpy(char *dest, char *src)
{
    int n = 0;

    while (src[n] != '\0') {
        dest[n] = src[n];
        ++n;
    }
    dest[n] = '\0';
    return (dest);
}