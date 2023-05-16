/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_arrayvisual
*/

#include <malloc.h>

char *my_superstrcat(int num, ...);
long int my_putstr(const char *str);
size_t my_arraylen(const char **array);
char *my_strjoin(const char **array, const char *join);;

char *my_arrayform(const char **array)
{
    char *ret = NULL;
    char *str = NULL;

    if (array == NULL)
        return NULL;
    str = my_strjoin(array, "', '");
    ret = my_superstrcat(3, "['", str, "']");
    free(str);
    return ret;
}

size_t my_arraydisp(const char **array)
{
    size_t len = my_arraylen(array);

    for (size_t n = 0; n < len; n ++) {
        my_putstr(array[n]);
        my_putstr("\n");
    }
    return len;
}
