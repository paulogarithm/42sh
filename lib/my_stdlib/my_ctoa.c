/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_ctoa
*/

#include <malloc.h>

char *my_ctoa(const char c)
{
    char *ret = malloc(sizeof(char) * 2);

    if (ret == NULL)
        return NULL;
    ret[0] = c;
    ret[1] = '\0';
    return ret;
}
