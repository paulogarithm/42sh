/*
** EPITECH PROJECT, 2023
** sh_re
** File description:
** misc
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#include "my/string.h"
#include "my/array.h"
#include "structure.h"

/* ... */
void nothing(int sig)
{
    (void)sig;
}

bool my_startswith(const char *str, const char *start)
{
    const size_t startlen = my_strlen(start);

    if (startlen > my_strlen(str))
        return false;
    for (size_t n = 0; n < startlen; n ++)
        if (str[n] != start[n])
            return false;
    return true;
}

char **my_filter_startswith(char **array, const char *starts)
{
    for (size_t n = 0; array[n] != NULL; ++n)
        if (!my_startswith(array[n], starts))
            my_arraypop(&array, n--);
    return array;
}
