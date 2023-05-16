/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen_max(char *str);

char *my_strcat_max(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);

    for (; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
