/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strcut
*/

#include <malloc.h>

size_t my_strlen(const char *str);

char *my_strcut(const char *str, int beg, int end)
{
    char *new = NULL;

    if (beg > end)
        return NULL;
    new = malloc(sizeof(char) * (end - beg + 2));
    if (new == NULL)
        return NULL;
    for (size_t n = beg; (int)n < end && str[n] != '\0'; n++)
        new[n - beg] = str[n];
    new[end - beg] = '\0';
    return new;
}
