/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_strcmp
*/

#include <stddef.h>
#include <stdbool.h>

size_t my_strlen(const char *str);

bool my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = 0;
    size_t len2 = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    len1 = my_strlen(s1);
    len2 = my_strlen(s2);
    if (len1 != len2)
        return 0;
    for (size_t n = 0; s1[n] != '\0'; n ++)
        if (s1[n] != s2[n])
            return 0;
    return 1;
}
