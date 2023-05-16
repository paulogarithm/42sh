/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_strcatx
*/

#include <malloc.h>
#include <stdarg.h>

size_t my_strlen(const char *str);
void my_addstr(char **a, const char *b);
char *my_newstr(const char *str);

char *my_strcat(char *restrict dest, const char *restrict src)
{
    const size_t alen = my_strlen((const char *)dest);
    const size_t blen = my_strlen(src);
    char *new = malloc(sizeof(char) * (alen + blen + 1));

    if (new == NULL)
        return NULL;
    for (size_t n = 0; n < alen; n ++)
        new[n] = dest[n];
    for (size_t n = 0; n < blen; n ++)
        new[alen + n] = src[n];
    new[alen + blen] = '\0';
    return new;
}

char *my_strncat(char *restrict dest, const char *restrict src, size_t len)
{
    const size_t alen = my_strlen((const char *)dest);
    char *new = malloc(sizeof(char) * (alen + len + 1));

    if (new == NULL)
        return NULL;
    for (size_t n = 0; n < alen; n ++)
        new[n] = dest[n];
    for (size_t n = 0; n < len; n ++)
        new[alen + n] = src[n];
    new[alen + len] = '\0';
    return new;
}

char *my_superstrcat(int num, ...)
{
    char *ret = my_newstr("");
    char *buf = NULL;
    va_list ap;

    va_start(ap, num);
    while (num-- > 0) {
        buf = va_arg(ap, char *);
        my_addstr(&ret, buf);
    }
    va_end(ap);
    return ret;
}
