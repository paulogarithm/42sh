/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_math
*/

int my_max(const int a, const int b)
{
    return ((a >= b) ? a : b);
}

int my_min(const int a, const int b)
{
    return ((a <= b) ? a : b);
}

int my_abs(const int a)
{
    return ((a < 0) ? -a : a);
}

int my_pow(const int a, const unsigned int b)
{
    int ret = 1;

    for (int i = 0; i < (int) b; i ++)
        ret *= a;
    return ret;
}
