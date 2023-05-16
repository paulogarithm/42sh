/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_writein
*/

#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#include <stdbool.h>

size_t my_strlen(const char *str);

bool my_serial(const char *file, const char *line, const char flags)
{
    int oflags = 0;
    int fd = -1;

    oflags |= ((flags & 1) ? O_CREAT : 0);
    oflags |= ((flags & 2) ? O_TRUNC : 0);
    oflags |= ((flags & 4) ? O_APPEND : 0);
    fd = open(file, oflags | O_WRONLY, 0644);
    if (fd < 0)
        return 1;
    if (write(fd, line, sizeof(char) * my_strlen(line)) < 0)
        return 1;
    return 0;
}
