/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strcpy
*/

#include <stddef.h>

char *my_strcpy(char *restrict dest, const char *restrict src)
{
    size_t n = 0;

    for (; src[n] != '\0'; n ++)
        dest[n] = src[n];
    dest[n] = '\0';
    return dest;
}

char *my_strncpy(char *restrict dest, const char *restrict src, size_t len)
{
    size_t n = 0;

    for (; src[n] != '\0' && n < len; n ++)
        dest[n] = src[n];
    dest[n] = '\0';
    return dest;
}
