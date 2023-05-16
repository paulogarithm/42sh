/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** unalias
*/

#include <stddef.h>

#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"
#include "structure.h"

short custom_unalias(const char **command, minish_t *minish)
{
    int pos = 0;

    if (my_strcmp(command[0], "unalias") == 0)
        return 0;
    if (my_arraylen(command) < 2)
        return my_printf("unalias: Too few arguments.\n");
    for (int n = 1; command[n] != NULL; ++n) {
        pos = get_alias_pos(minish->aliases, (const char *)command[n]);
        if (pos < 0)
            continue;
        my_arraypop(&minish->aliases, pos);
    }
    return 1;
}
