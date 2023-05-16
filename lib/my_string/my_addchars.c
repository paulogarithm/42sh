/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_addchar
*/

#include <malloc.h>
#include <stdbool.h>

int my_strlen(const char *str);
void *my_realloc(void *src, size_t old_size, size_t size);

void my_addchar(char **str, char c)
{
    const int len = (my_strlen((const char *)*str));
    char *new = malloc(sizeof(char) * (len + 2));

    if (new == NULL)
        return;
    for (int n = 0; n < len; n ++)
        new[n] = (*str)[n];
    new[len] = c;
    new[len + 1] = '\0';
    free(*str);
    *str = new;
}

void my_addcharindex(char **str, char c, const size_t index)
{
    char *new = malloc(sizeof(char));
    bool putted = false;

    if (new == NULL)
        return;
    new[0] = '\0';
    for (size_t n = 0; (*str)[n] != '\0'; n ++) {
        if (n == index && !putted) {
            my_addchar(&new, c);
            putted = true;
        }
        my_addchar(&new, (*str)[n]);
    }
    if (!putted)
        my_addchar(&new, c);
    free(*str);
    *str = new;
}

void my_addstr(char **a, const char *b)
{
    const int alen = (my_strlen((const char *)*a));
    const int blen = (my_strlen((const char *)b));
    char *new = malloc(sizeof(char) * (alen + blen + 1));

    if (new == NULL)
        return;
    for (int n = 0; n < alen; n ++)
        new[n] = (*a)[n];
    for (int n = 0; n < blen; n ++)
        new[alen + n] = b[n];
    new[alen + blen] = '\0';
    free(*a);
    *a = new;
}
