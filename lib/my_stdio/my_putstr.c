/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_putstr
*/

#include <unistd.h>

size_t my_strlen(const char *str);

void my_putchar(char c)
{
    write(STDOUT_FILENO, &c, sizeof(char));
}

ssize_t my_putstr(const char *str)
{
    return write(STDOUT_FILENO, str, my_strlen(str) * sizeof(char));
}

ssize_t my_putstrd(int fd, const char *str)
{
    return write(fd, str, my_strlen(str) * sizeof(char));
}
