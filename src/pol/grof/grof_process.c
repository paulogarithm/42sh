/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** process_grof
*/

#include <iso646.h>
#include <stdbool.h>
#include <malloc.h>
#include "my/string.h"
#include "my/stdio.h"
#include "my/array.h"

#include "grof/functions.h"

static const tabgrof_actions_t TAB_GROF[] = {
    {"exp", grof_create_var},
    {"for", grof_for_loop},
    {NULL, NULL}
};

static void variable_show(grof_t *grof)
{
    for (size_t n = 0; grof->variables[n] != NULL; ++n) {
        var_t *var = grof->variables[n];
        my_printf("[%d] %s = %s\n", var->type, var->name, var->value);
    }
}

bool grof_process(grof_t *grof)
{
    char *word = NULL;
    bool ret = true;
    size_t len = my_arraylen((const char **)grof->words);
    short pos = 0;

    for (size_t n = 0; n < len and ret; ++n) {
        word = grof->words[n];
        pos = grof_tabpos_actions(word, TAB_GROF);
        if (grof_isfunction(grof, &n))
            continue;
        if (pos < 0)
            return false;
        ret = ((not ret) ? ret : TAB_GROF[pos].function(grof, &n));
    }
    (void)variable_show;
    return ret;
}

bool grof_simulate(grof_t *grof, char *str)
{
    char **old_words = my_newarray((const char **)grof->words);
    char **new_words = my_array_str(str);

    if (new_words == NULL)
        return false;
    free(grof->words);
    grof->words = new_words;
    if (grof_process(grof))
        return false;
    free(grof->words);
    grof->words = old_words;
    return true;
}
