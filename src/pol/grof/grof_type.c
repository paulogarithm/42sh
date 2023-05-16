/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_type
*/

#include <iso646.h>
#include <stddef.h>
#include <malloc.h>
#include "my/stdlib.h"
#include "my/string.h"

#include "structure.h"
#include "grof/grof.h"

char *grof_get_varvalue(grof_t *grof, const char *varname)
{
    for (size_t n = 0; grof->variables[n] != NULL; ++n)
        if (my_strcmp(grof->variables[n]->name, varname))
            return grof->variables[n]->value;
    return NULL;
}

static void check_env_val(grof_t *grof, char **varval, const char *str)
{
    char *ret = NULL;
    char *cut = NULL;
    char *tmp = NULL;

    if (*varval != NULL or str[0] != '$')
        return;
    cut = my_strcut(str, 1, my_strlen(str));
    tmp = get_envval((const char **)grof->minish->env, cut);
    free(cut);
    if (tmp == NULL)
        return;
    ret = my_superstrcat(3, "\"", tmp, "\"");
    free(tmp);
    *varval = ret;
}

bool grof_replacevar(grof_t *grof, char ***array)
{
    char *varval = NULL;

    for (size_t n = 0; (*array)[n] != NULL; ++n) {
        varval = grof_get_varvalue(grof, (*array)[n]);
        check_env_val(grof, &varval, (*array)[n]);
        if (varval == NULL)
            continue;
        free((*array)[n]);
        (*array)[n] = my_newstr(varval);
    }
    return true;
}

unsigned short grof_get_type(grof_t *grof, const char *str)
{
    char *varvalue = NULL;
    unsigned short ret = 0;

    if (str == NULL or my_strcmp(str, "nil"))
        return G_NIL;
    if (my_isnum(str) or my_isdouble(str))
        return G_NUMBER;
    if (my_strlen(str) >= 3 and
    str[0] == '"' and str[my_strlen(str) - 1] == '"')
        return G_STRING;
    if (my_strcmp(str, "true") or my_strcmp(str, "false"))
        return G_BOOLEAN;
    if (str[0] == '{')
        return G_TABLE;
    varvalue = grof_get_varvalue(grof, str);
    if (varvalue == NULL)
        return G_NIL;
    ret = grof_get_type(grof, varvalue);
    return ret;
}
