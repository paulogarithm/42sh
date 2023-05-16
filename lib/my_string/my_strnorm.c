/*
** EPITECH PROJECT, 2023
** parcing_map_csfml
** File description:
** my_strnorm
*/

#include <stddef.h>

char *my_strjoin(const char **array, const char *join);
void my_arrayfree(char **array);
char **my_array_str(const char *str);

char *my_strnorm(const char *str)
{
    char **array = my_array_str(str);
    char *new = NULL;

    if (array == NULL)
        return NULL;
    new = my_strjoin((const char **)array, " ");
    if (new == NULL) {
        my_arrayfree(array);
        return NULL;
    }
    my_arrayfree(array);
    return new;
}
