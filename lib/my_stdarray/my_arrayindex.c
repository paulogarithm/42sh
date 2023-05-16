/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** my_arrayindex
*/

#include <stddef.h>
#include <stdbool.h>

bool my_strcmp(const char *a, const char *b);

long int my_arrayindex(const char **array, const char *str)
{
    for (size_t n = 0; array[n] != NULL; n++)
        if (my_strcmp(array[n], str))
            return n;
    return -1;
}
