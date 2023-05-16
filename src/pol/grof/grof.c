/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof
*/

#include <stdbool.h>
#include <iso646.h>
#include <malloc.h>

#include "my/string.h"
#include "my/array.h"

#include "grof/functions.h"

static grof_t *grof_setup(char **words)
{
    grof_t *grof = malloc(sizeof(grof_t));

    if (grof == NULL)
        return NULL;
    grof->variables = malloc(sizeof(var_t *));
    grof->variables[0] = NULL;
    grof->words = words;
    return grof;
}

bool grof(char *line, minish_t *minish)
{
    char **word_array = NULL;
    grof_t *grof = NULL;

    if (line == NULL)
        return false;
    word_array = my_array_str(line);
    if (word_array == NULL)
        return false;
    grof = grof_setup(word_array);
    if (grof == NULL)
        return false;
    grof->minish = minish;
    return grof_process(grof);
}
