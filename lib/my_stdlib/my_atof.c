/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_atof
*/

#include <stdbool.h>
#include <stddef.h>

static bool process_digit
(const char c, bool *decimal, double *frac, double *ret)
{
    if (c == '.') {
        (*decimal) = true;
        return 0;
    }
    if (c < '0' || c > '9')
        return 1;
    if (*decimal) {
        (*frac) *= 0.1f;
        (*ret) += (c - '0') * (*frac);
    } else
        (*ret) = (*ret) * 10 + (c - '0');
    return 0;
}

double my_atof(const char *str)
{
    double ret = 0;
    double frac = 1;
    short mul = 0;
    bool decimal = 0;
    bool val = 0;

    if (str == NULL)
        return 0;
    mul = ((str[0] == '-') ? -1 : 1);
    for (size_t i = (mul < 0); str[i] != '\0'; i++) {
        val = process_digit(str[i], &decimal, &frac, &ret);
        if (val)
            return 0;
    }
    return ret * mul;
}
