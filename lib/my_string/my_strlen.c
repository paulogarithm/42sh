/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_strlen
*/

#include <stddef.h>

size_t my_strlen(const char *str)
{
    int n = 0;
    for (; str[n] != '\0'; n ++);
    return n;
}
