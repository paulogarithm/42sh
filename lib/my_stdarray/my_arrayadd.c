/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_arrayapnd
*/

#include <malloc.h>

char *my_newstr(const char *str);

void my_arrayadd(char ***array, const char *str)
{
    char **new = 0;
    size_t len = 0;

    for (; (*array)[len] != NULL; len ++);
    new = malloc(sizeof(char *) * (len + 2));
    if (new == NULL)
        return;
    for (size_t n = 0; n < len; n ++)
        new[n] = (*array)[n];
    new[len] = my_newstr(str);
    new[len + 1] = NULL;
    free(*array);
    *array = new;
}
