/*
** EPITECH PROJECT, 2023
** sh_merge
** File description:
** termios_history_ncommand
*/

#include <malloc.h>
#include <iso646.h>

#include "my/string.h"
#include "my/stdio.h"
#include "my/array.h"
#include "my/stdlib.h"

#include "structure.h"

static bool n_get_command(char **input, minish_t *minish, int num)
{
    char *command = NULL;

    if (num == 0)
        return false;
    command = history_getcommand((unsigned)(num - 1), minish);
    if (command == NULL)
        return false;
    *input = my_superstrcat(2, command, " ");
    free(command);
    return true;
}

bool n_command(char **input, minish_t *minish, bool realtime)
{
    char **split = my_array_str((const char *)(*input));
    char *numcut = NULL;
    int num = 0;

    if (split == NULL || my_arraylen((const char **)split) != 1)
        return false;
    if (split[0][0] != '!' ||
    (realtime && (*input)[my_strlen(*input) - 1] != ' '))
        return false;
    numcut = my_strcut((const char *)split[0], 1, my_strlen(split[0]));
    if (!my_isnum(numcut))
        return false;
    num = my_atoi(numcut);
    if (num < 0)
        num =
        my_arraylen((const char **)minish->history_parser) - my_abs(num) + 1;
    return n_get_command(input, minish, num);
}
