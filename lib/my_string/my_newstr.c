/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_newchars
*/

#include <malloc.h>

size_t my_strlen(const char *str);

char *my_newstr(const char *str)
{
    const size_t len = ((str == NULL) ? 0 : my_strlen(str));
    char *res = malloc(sizeof(char) * (len + 1));

    if (res == NULL)
        return NULL;
    for (size_t n = 0; n < len; n ++)
        res[n] = str[n];
    res[len] = '\0';
    return res;
}

char *my_newnstr(const char *str, size_t n)
{
    const size_t len = ((str == NULL) ? 0 : my_strlen(str));
    char *res = malloc(sizeof(char) * (len + 1));

    if (res == NULL)
        return NULL;
    for (size_t i = 0; i < len && i < n; i ++)
        res[i] = str[i];
    res[len] = '\0';
    return res;
}
