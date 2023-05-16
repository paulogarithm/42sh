/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_scanf
*/

#include <stdbool.h>
#include <unistd.h>
#include <malloc.h>

char *my_newstr(const char *str);
void my_addchar(char **str, char c);
ssize_t my_putstr(const char *str);

char *my_scanf(const char *toshow)
{
    char *ret = my_newstr("");
    char *tmp = NULL;
    ssize_t readres = 0;
    const bool __ = true;

    my_putstr(toshow);
    for (; __ ;) {
        tmp = my_newstr("?");
        readres = read(STDIN_FILENO, tmp, sizeof(char));
        if (readres <= 0 || tmp[0] == '\n')
            break;
        my_addchar(&ret, tmp[0]);
        free(tmp);
    }
    free(tmp);
    return ret;
}
