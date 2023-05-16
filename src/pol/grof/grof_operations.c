/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_operations
*/

#include <stddef.h>
#include <stdbool.h>
#include "my/string.h"
#include "my/stdlib.h"

#include "grof/functions.h"
#include "grof/operations.h"

void operation_plus(grof_t *grof, char ***array, size_t n)
{
    switch (grof_get_type(grof, (*array)[n - 1])) {
        case G_STRING:
        (*array)[n - 1] = my_strcat((*array)[n - 1], (*array)[n + 1]);
        break;
        case G_NUMBER:
        (*array)[n - 1] =
        my_ftoa(my_atof((*array)[n - 1]) + my_atof((*array)[n + 1]));
        break;
        case G_BOOLEAN:
        (*array)[n - 1] =
        my_btoa((my_atob((*array)[n - 1]) + my_atob((*array)[n + 1])) != 0);
        break;
        default:
        (*array)[n - 1] = my_newstr("nil");
        break;
    }
}

void operation_minus(grof_t *grof, char ***array, size_t n)
{
    switch (grof_get_type(grof, (*array)[n - 1])) {
        case G_STRING:
        (*array)[n - 1] = remove_string((*array)[n - 1], (*array)[n + 1]);
        break;
        case G_NUMBER:
        (*array)[n - 1] =
        my_ftoa(my_atof((*array)[n - 1]) - my_atof((*array)[n + 1]));
        break;
        case G_BOOLEAN:
        (*array)[n - 1] =
        my_btoa((my_atob((*array)[n - 1]) - my_atob((*array)[n + 1])) != 0);
        break;
        default:
        (*array)[n - 1] = my_newstr("nil");
        break;
    }
}
