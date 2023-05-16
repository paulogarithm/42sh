/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_arraypop
*/

#include <malloc.h>

void my_arrayfree(char **array);
char *my_newstr(const char *str);

void my_arraypop(char ***array, const size_t pos)
{
    size_t len = 0;
    char **new = NULL;

    for (len = 0; (*array)[len] != NULL; len++);
    new = malloc(sizeof(char *) * len);
    if (new == NULL)
        return;
    for (size_t n = 0; n < len - 1; n++) {
        if (n < pos)
            new[n] = my_newstr((*array)[n]);
        else
            new[n] = my_newstr((*array)[n + 1]);
    }
    new[len - 1] = NULL;
    free((*array)[pos]);
    free(*array);
    *array = new;
}

void my_arraysuperpop(char ***array, const size_t pos, const size_t num)
{
    for (size_t n = 0; n < num && (*array)[pos] != NULL; n++)
        my_arraypop(array, pos);
}
