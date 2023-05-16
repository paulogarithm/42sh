/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** misc_array
*/

#include <stdlib.h>

#include "my.h"

int my_arrayindex(char **array, char *str)
{
    for (int n = 0; array[n] != NULL; n++)
        if (my_strcmp(array[n], str))
            return n;
    return -1;
}

void my_arraysuperpop(char ***array, const int pos, const int num)
{
    for (int n = 0; n < num && (*array)[pos] != NULL; n++)
        my_arraypop(array, pos);
}

char **my_arraycut(char **origin, int beggin, int end)
{
    char **ret = NULL;

    if (origin == NULL || end < beggin || beggin < 0)
        return NULL;
    ret = malloc(sizeof(char *));
    if (ret == NULL)
        return NULL;
    ret[0] = NULL;
    for (int n = beggin; n <= end && origin[n] != NULL; n++)
        my_arrayadd(&ret, origin[n]);
    return ret;
}

int my_anyarraylen(void **array)
{
    int n = 0;
    for (; array[n] != NULL; n++)
        ;
    return n;
}
