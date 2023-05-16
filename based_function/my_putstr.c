/*
** EPITECH PROJECT, 2021
** Task02 - my_putstr.c
** File description:
** abc
*/

#include <unistd.h>

int my_strlen_max(char const *chr);

int my_putstr_max(char const *str)
{
    write(1, str, my_strlen_max(str));
    return 0;
}
