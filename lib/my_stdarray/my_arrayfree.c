/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_arrayfree
*/

#include <stddef.h>
#include <malloc.h>

void my_arrayfree(char **array)
{
    if (array == NULL)
        return;
    for (int n = 0; array[n] != NULL; ++n)
        free(array[n]);
    free(array);
}
