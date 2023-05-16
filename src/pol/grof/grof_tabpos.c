/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_tabpos
*/

#include <stddef.h>
#include "my/string.h"

#include "grof/grof.h"

short grof_tabpos_actions(const char *str, const tabgrof_actions_t *TAB_GROF)
{
    for (unsigned short n = 0; TAB_GROF[n].flag != NULL; ++n)
        if (my_strcmp(TAB_GROF[n].flag, str))
            return n;
    return -1;
}

short grof_tabpos_builtins(const char *str, const tabgrof_builtins_t *TAB_GROF)
{
    for (unsigned short n = 0; TAB_GROF[n].flag != NULL; ++n)
        if (my_strcmp(TAB_GROF[n].flag, str))
            return n;
    return -1;
}
