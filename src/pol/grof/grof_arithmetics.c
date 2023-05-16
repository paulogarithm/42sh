/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_arithmetic
*/


#include <iso646.h>
#include <stddef.h>
#include <malloc.h>
#include "my/string.h"
#include "my/stdlib.h"
#include "my/array.h"
#include "my/stdio.h"

#include "grof/functions.h"
#include "grof/operations.h"

static const tabgrof_operations_t LIST[] = {
    {"+", operation_plus},
    {"-", operation_minus},
    {NULL, NULL}
};

static short get_operation_pos(const char *ope)
{
    for (unsigned short n = 0; LIST[n].operation != NULL; ++n)
        if (my_strcmp(ope, LIST[n].operation))
            return n;
    return -1;
}

static void process_arithmetics(grof_t *grof, char ***array, size_t *n)
{
    short pos = get_operation_pos((*array)[*n]);

    if (pos < 0)
        (*array)[*n - 1] = NULL;
    else
        LIST[pos].function(grof, array, *n);
    my_arraypop(array, *n + 1);
    my_arraypop(array, *n);
    *n -= 1;
}

static void loop_arithmetics(grof_t *grof, char ***array)
{
    const char *ARITHMETICS[] = {"+", "-", "*", "/", NULL};

    for (size_t n = 0; (*array)[n] != NULL; ++n)
        if (my_arrayindex(ARITHMETICS, (*array)[n]) >= 0)
            process_arithmetics(grof, array, &n);
}

static void beautiful_num(grof_t *grof, char **ret)
{
    char *tmp = NULL;
    enum mode_e type = grof_get_type(grof, *ret);

    if (type == G_NIL) {
        free(*ret);
        *ret = my_newstr("nil");
    } if (type != G_NUMBER)
        return;
    if (my_atoi(*ret) == my_atof(*ret)) {
        tmp = my_itoa(my_atoi(*ret));
        free(*ret);
        *ret = tmp;
        return;
    }
    for (size_t n = my_strlen(*ret) - 1; n > 0; --n)
        if ((*ret)[n] == '0')
            (*ret)[n] = '\0';
}

char *grof_arithmetics(grof_t *grof, char *str)
{
    char **array = my_array_str(str);
    char *ret = NULL;

    if (not grof_replacevar(grof, &array))
        return NULL;
    loop_arithmetics(grof, &array);
    if (array[0] == NULL)
        return NULL;
    ret = my_newstr(array[0]);
    beautiful_num(grof, &ret);
    my_arrayfree(array);
    return ret;
}
