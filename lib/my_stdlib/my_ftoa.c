/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_ftoa
*/

#include <stddef.h>
#include <malloc.h>

char *my_superstrcat(int num, ...);
char *my_itoa(const int nb);
int my_abs(const int a);

char *my_ftoa(const double num)
{
    char *str = NULL;
    int a = (int)num;
    int b = (int)((num - a) * 10000);
    char *a_str = my_itoa(a);
    char *b_str = my_itoa(my_abs(b));

    str = my_superstrcat(3, a_str, ".", b_str);
    free(a_str);
    free(b_str);
    return str;
}
