/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** my_arraycat
*/

#include <stddef.h>
#include <malloc.h>

char *my_newstr(const char *str);
char **my_newarray(const char **array);
void my_arrayadd(char ***array, const char *str);

char **my_arraycat(char **a, char **b)
{
    char *str = NULL;
    char **new = my_newarray(NULL);

    if (a != NULL)
        for (size_t n = 0; a[n] != NULL; n++) {
            str = my_newstr(a[n]);
            my_arrayadd(&new, str);
            free(str);
        }
    if (b != NULL)
        for (size_t n = 0; b[n] != NULL; n++) {
            str = my_newstr(b[n]);
            my_arrayadd(&new, str);
            free(str);
        }
    return new;
}
