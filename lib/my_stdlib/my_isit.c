/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_isit
*/

#include <stdbool.h>
#include <stddef.h>

size_t my_strlen(const char *str);

bool my_isalphanum(const char *str)
{
    for (int n = 0; str[n] != '\0'; n ++)
        if ((str[n] < 'A' || str[n] > 'Z')
        && (str[n] < '0' || str[n] > '9')
        && (str[n] < 'a' || str[n] > 'z'))
            return 0;
    return 1;
}

bool my_isnum(const char *str)
{
    int i = 0;

    if (str[i] == '-' && my_strlen(str) >= 2)
        i += 1;
    for (int n = i; str[n] != '\0'; n ++)
        if (str[n] < '0' || str[n] > '9')
            return 0;
    return 1;
}

bool my_isdouble(const char *str)
{
    int i = 0;
    int has_point = 0;

    if (str[i] == '-' && my_strlen(str) >= 2)
        i += 1;
    for (int n = i; str[n] != '\0'; n ++) {
        if (((str[n] < '0' || str[n] > '9') && str[n] != '.') ||
        (has_point && str[n] == '.'))
            return 0;
        if (str[n] == '.')
            has_point = 1;
    }
    return 1;
}
