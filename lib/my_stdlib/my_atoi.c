/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_atoi
*/

#include <stddef.h>

int my_atoi(const char *str)
{
    int ret = 0;
    short mul = 0;
    short num = 0;

    if (str == NULL)
        return 0;
    mul = ((str[0] == '-') ? -1 : 1);
    for (size_t n = (mul < 0); str[n] != '\0'; n ++) {
        if (str[n] < '0' || str[n] > '9')
            break;
        ret *= 10;
        num = str[n] - '0';
        ret += num;
    }
    return (ret * mul);
}

long my_atol(const char *str)
{
    long ret = 0;
    short mul = 0;
    short num = 0;

    if (str == NULL)
        return 0;
    mul = ((str[0] == '-') ? -1 : 1);
    for (size_t n = (mul < 0); str[n] != '\0'; n ++) {
        if (str[n] < '0' || str[n] > '9')
            return 0;
        ret *= 10;
        num = str[n] - '0';
        ret += num;
    }
    return (ret * mul);
}

long long my_atoll(const char *str)
{
    long long ret = 0;
    short mul = 0;
    short num = 0;

    if (str == NULL)
        return 0;
    mul = ((str[0] == '-') ? -1 : 1);
    for (size_t n = (mul < 0); str[n] != '\0'; n ++) {
        if (str[n] < '0' || str[n] > '9')
            return 0;
        ret *= 10;
        num = str[n] - '0';
        ret += num;
    }
    return (ret * mul);
}
