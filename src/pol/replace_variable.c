/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** replace_variable
*/

#include <stdbool.h>
#include <iso646.h>
#include <malloc.h>
#include "my/string.h"
#include "my/stdlib.h"

#include "tab.h"
#include "structure.h"

static char *special_var(char *key, minish_t *minish)
{
    if (not my_strcmp(key, "?"))
        return NULL;
    return my_itoa(minish->return_value);
}

static char *check_var(char **array, size_t n, minish_t *minish)
{
    char *key = my_strcut(array[n], 1, my_strlen(array[n]));

    free(array[n]);
    if (special_var(key, minish) != NULL)
        return special_var(key, minish);
    if (get_envpos((const char **)minish->env, key) < 0)
        return my_newstr(NULL);
    return get_envval((const char **)minish->env, key);
}

void replace_var(char **array, minish_t *minish)
{
    for (size_t n = 0; array[n] != NULL; ++n)
        if (array[n][0] == '$')
            array[n] = check_var(array, n, minish);
}
