/*
** EPITECH PROJECT, 2023
** sh_re
** File description:
** env
*/

#include <stdlib.h>

#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"
#include "my/stdlib.h"

int get_envpos(const char **env, const char *key)
{
    char **split = NULL;

    if (env == NULL || env[0] == NULL || key == NULL)
        return -1;
    for (int n = 0; env[n] != NULL; n++) {
        split = my_strsplit(env[n], "=");
        if (!my_strcfnd(env[n], '=')) {
            free(split);
            continue;
        }
        if (!my_strcmp(split[0], key)) {
            my_arrayfree(split);
            continue;
        }
        my_arrayfree(split);
        return n;
    }
    return -1;
}

char *get_envval(const char **env, const char *key)
{
    char **split = NULL;
    char *ret = NULL;
    int pos = 0;

    pos = get_envpos(env, key);
    if (pos == -1)
        return NULL;
    split = my_strsplit(env[pos], "=");
    if (split == NULL)
        return NULL;
    ret = split[1] == NULL ? my_newstr("") : my_newstr(split[1]);
    my_arrayfree(split);
    return ret;
}

static short int setenv_checkstring(char **array)
{
    if (my_arraylen((const char **)array) >= 4)
        return my_printf("setenv: Too many arguments.\n");
    if (my_strlen(array[1]) == 0 || (array[1][0] != '_' &&
    (array[1][0] < 'a' || array[1][0] > 'z') &&
    (array[1][0] < 'A' || array[1][0] > 'Z')))
        return my_printf("setenv: Variable name must begin with a letter.\n");
    if (!my_isalphanum(array[1]))
        return my_printf(
            "setenv: Variable name must contain alphanumeric characters.\n");
    return 0;
}

short custom_setenv(char **array, char ***env)
{
    char *res = NULL;
    int pos = get_envpos((const char **)*env, array[1]);

    if (!my_strcmp(array[0], "setenv"))
        return 0;
    if (my_arraylen((const char **)array) == 1)
        return 1 + my_arraydisp((const char **)*env);
    if (setenv_checkstring(array))
        return 1;
    res = my_newstr(array[1]);
    my_addstr(&res, "=");
    my_addstr(&res, array[2] != NULL ? array[2] : "");
    if (pos < 0) {
        my_arrayadd(env, res);
        free(res);
    } else {
        free((*env)[pos]);
        (*env)[pos] = res;
    }
    return 1;
}

short custom_unsetenv(char **array, char ***env)
{
    int pos = 0;

    if (!my_strcmp(array[0], "unsetenv"))
        return 0;
    if (my_arraylen((const char **)array) == 1)
        return my_printf("unsetenv: Too few arguments.\n");
    for (int n = 1; array[n] != NULL; n++) {
        pos = get_envpos((const char **)(*env), array[n]);
        if (pos < 0)
            continue;
        my_arraypop(env, pos);
    }
    return 1;
}
