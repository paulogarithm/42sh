/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_arraylen
*/

#include <stddef.h>

size_t my_arraylen(const char **array)
{
    size_t len = 0;

    if (array == NULL)
        return 0;
    for (; array[len] != NULL; len ++);
    return len;
}
