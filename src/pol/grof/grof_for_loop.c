/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_for_loop
*/

#include <iso646.h>
#include <malloc.h>
#include "my/string.h"
#include "my/stdio.h"
#include "my/array.h"
#include "my/stdlib.h"

#include "grof/functions.h"
#include "structure.h"

static char **treat_cond(char *cond)
{
    char **ret = my_strsplit(cond, ",");
    return ret;
}

static char **get_cond(grof_t *grof, size_t *n)
{
    char *ret = my_newstr(NULL);
    const size_t begin = *n + 1;

    *n += 1;
    for (; grof->words[*n] != NULL; ++(*n)) {
        if (my_strcmp(grof->words[*n], "do"))
            return treat_cond(ret);
        my_addstr(&ret, ((*n == begin) ? "" : " "));
        my_addstr(&ret, grof->words[*n]);
    }
    return NULL;
}

static char *get_action(grof_t *grof, size_t *n, char **cond)
{
    char *ret = my_newstr(NULL);
    const size_t begin = *n + 1;

    if (cond == NULL) {
        free(ret);
        return NULL;
    }
    *n += 1;
    for (; grof->words[*n] != NULL; ++(*n)) {
        if (my_strcmp(grof->words[*n], "end"))
            return ret;
        my_addstr(&ret, ((*n == begin) ? "" : " "));
        my_addstr(&ret, grof->words[*n]);
    }
    return NULL;
}

static int *check_cond(char **cond)
{
    int *ret = NULL;
    char **keyval = keyvalue_parser(cond[0]);
    char *tmp = my_strnorm(cond[1]);
    char *tmp2 = ((cond[2] != NULL) ? my_strnorm(cond[2]) : NULL);
    int base = 1;

    if (keyval == NULL)
        return NULL;
    ret = malloc(sizeof(int) * 3);
    if (ret == NULL)
        return NULL;
    ret[0] = my_atoi(keyval[1]);
    ret[1] = my_atoi(tmp);
    free(tmp);
    base = ((ret[0] > ret[1]) ? -1 : 1);
    ret[2] = ((tmp2 != NULL) ? my_atoi(tmp2) : base);
    free(tmp2);
    ret[2] = ((ret[2] == 0) ? base : ret[2]);
    return ret;
}

bool grof_for_loop(grof_t *g, size_t *n)
{
    char **cond = get_cond(g, n);
    char *actions = get_action(g, n, cond);
    int *cond_vals = NULL;
    char **kv = NULL;

    if (cond == NULL or my_arraylen((const char **)cond) < 2 or actions == NULL)
        return false;
    cond_vals = check_cond(cond);
    if (cond_vals == NULL)
        return false;
    kv = keyvalue_parser(cond[0]);
    for (int n = cond_vals[0]; ((cond_vals[2] > 0) ?
    n < cond_vals[1] : n > cond_vals[1]); n += cond_vals[2]) {
        if (not grof_autovar(g, my_superstrcat(3, kv[0], " = ", my_itoa(n))))
            return false;
        grof_simulate(g, actions);
    }
    return true;
}
