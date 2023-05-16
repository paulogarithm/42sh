/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_builtins
*/

#include <stdbool.h>
#include <iso646.h>
#include "my/string.h"
#include "my/stdio.h"

#include "grof/functions.h"

bool grof_builtins_exec(grof_t *grof, char **keyval)
{
    struct binary_tree *bt = NULL;
    if (call_binary_tree(grof->minish, bt, keyval[1]) == -1)
        return false;
    return true;
}

static char *realval(grof_t *grof, char *str)
{
    return grof_arithmetics(grof, str);
}

bool grof_builtins_print(grof_t *grof, char **keyval)
{
    char **to_print = my_strsplit(keyval[1], ",");
    char *val = NULL;

    if (to_print == NULL)
        return false;
    for (size_t n = 0; to_print[n] != NULL; ++n) {
        val = realval(grof, to_print[n]);
        my_printf("%s", ((n > 0) ? ", " : ""));
        my_printf("%s", ((val != NULL) ? val : "nil"));
    }
    my_printf("\n");
    return true;
}
