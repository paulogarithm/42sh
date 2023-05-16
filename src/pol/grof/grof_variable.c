/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_variable
*/

#include <malloc.h>
#include "my/string.h"

#include "grof/functions.h"

var_t *get_variable_by_name(grof_t *grof, const char *name)
{
    for (size_t n = 0; grof->variables[n] != NULL; ++n)
        if (my_strcmp(grof->variables[n]->name, name))
            return grof->variables[n];
    return NULL;
}

bool grof_newval_var(grof_t *grof, var_t *var)
{
    var_t *old_var = get_variable_by_name(grof, var->name);

    if (old_var == NULL)
        return false;
    old_var->value = my_newstr(var->value);
    old_var->type = var->type;
    free(var->name);
    free(var->value);
    free(var);
    return true;
}

bool grof_append_var(grof_t *grof, var_t *var)
{
    var_t **new = NULL;
    size_t len = 0;
    char *tmp = grof_get_varvalue(grof, var->name);

    if (tmp != NULL) {
        free(tmp);
        return grof_newval_var(grof, var);
    }
    free(tmp);
    for (; grof->variables[len] != NULL; ++len);
    new = malloc(sizeof(var_t) * (len + 2));
    if (new == NULL)
        return false;
    for (size_t n = 0; n < len; ++n)
        new[n] = grof->variables[n];
    new[len] = var;
    new[len + 1] = NULL;
    free(grof->variables);
    grof->variables = new;
    return true;
}
