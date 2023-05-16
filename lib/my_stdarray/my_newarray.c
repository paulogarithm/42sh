/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** my_newarray
*/

#include <malloc.h>

char *my_newstr(const char *str);
size_t my_arraylen(const char **array);

char **my_newarray(const char **array)
{
    size_t len = my_arraylen(array);
    char **dup = malloc(sizeof(char *) * (len + 1));

    for (size_t n = 0; n < len; n ++)
        dup[n] = my_newstr(array[n]);
    dup[len] = NULL;
    return dup;
}
