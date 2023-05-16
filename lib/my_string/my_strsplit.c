/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_array_str
*/

#include <malloc.h>

size_t my_strlen(const char *str);
char *my_strcut(const char *str, int beg, int end);
void my_addstr(char **dest, const char *add);
char *my_newstr(const char *text);
long int my_strcfnd(const char *str, const char c);
void my_arrayadd(char ***array, char *str);

static void do_cut(char ***array, char **cut, size_t n, size_t *old)
{
    if (*cut == NULL)
        return;
    if (!my_strlen(*cut)) {
        free(*cut);
        return;
    }
    my_arrayadd(array, *cut);
    free(*cut);
    *old = n + 1;
}

char **my_strsplit(const char *restrict str, const char *restrict correct)
{
    char **array = malloc(sizeof(char *));
    char *cut = NULL;
    size_t old = 0;

    if (array == NULL)
        return NULL;
    array[0] = NULL;
    for (size_t n = 0; str[n] != '\0'; n++) {
        if (my_strcfnd(correct, str[n]) >= 0 && old != n) {
            cut = my_strcut(str, old, n);
            do_cut(&array, &cut, n, &old);
        }
        if (my_strcfnd(correct, str[n]) >= 0 && old == n)
            old = n + 1;
    }
    cut = my_strcut(str, old, my_strlen(str));
    do_cut(&array, &cut, 0, &old);
    return array;
}

char **my_array_str(const char *str)
{
    return my_strsplit(str, " \t\n");
}

char *my_strjoin(const char **array, const char *join)
{
    char *ret = my_newstr(NULL);

    for (int n = 0; array[n] != NULL; n++) {
        if (n && join)
            my_addstr(&ret, join);
        my_addstr(&ret, array[n]);
    }
    return ret;
}
