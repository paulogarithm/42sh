/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_function
*/

#include <stdbool.h>
#include <iso646.h>
#include <stddef.h>
#include <malloc.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "structure.h"
#include "grof/functions.h"

static const tabgrof_builtins_t TAB_GROF[] = {
    {"exec", grof_builtins_exec},
    {"print", grof_builtins_print},
    {NULL, NULL}
};

static void clean_it(char **str)
{
    char *ret = NULL;
    long pos = my_strcfnd(*str, '(');

    if (pos < 0)
        return;
    ret = my_strcut(*str, pos + 1, my_strlen(*str) - 2);
    free(*str);
    *str = ret;
}

static char *get_value(grof_t *grof, size_t *n)
{
    char *ret = my_newstr(NULL);

    for (; grof->words[*n] != NULL; ++(*n)) {
        my_addstr(&ret, grof->words[*n]);
        my_addstr(&ret, " ");
        if (grof->words[*n][my_strlen(grof->words[*n]) - 1] == ')') {
            clean_it(&ret);
            return ret;
        }
    }
    free(ret);
    return NULL;
}

static bool basic_errorcase(grof_t *grof, size_t n)
{
    if (grof->words[n] == NULL)
        return true;
    if (my_strcfnd(grof->words[n], '(') < 0)
        return true;
    return false;
}

static char **check_form(grof_t *grof, size_t *n)
{
    char **array = NULL;
    char **ret = NULL;
    char *value = NULL;

    if (basic_errorcase(grof, *n))
        return NULL;
    array = my_strsplit(grof->words[*n], "(");
    if (array == NULL or array[0] == NULL or
    not my_startswith(grof->words[*n], array[0]))
        return NULL;
    value = get_value(grof, n);
    if (value == NULL)
        return NULL;
    ret = my_newarray(NULL);
    my_arrayadd(&ret, array[0]);
    my_arrayadd(&ret, value);
    free(value);
    my_arrayfree(array);
    return ret;
}

bool grof_isfunction(grof_t *grof, size_t *n)
{
    char **function_elements = check_form(grof, n);
    short pos = 0;

    if (function_elements == NULL)
        return false;
    pos = grof_tabpos_builtins(function_elements[0], TAB_GROF);
    if (pos < 0)
        return false;
    return TAB_GROF[pos].function(grof, function_elements);
}
