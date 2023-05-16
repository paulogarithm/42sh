/*
** EPITECH PROJECT, 2021
** myPutChar
** File description:
** abc.
*/

#include <unistd.h>

int my_putchar_max(char word)
{
    write(1, &word, 1);
    return 0;
}
