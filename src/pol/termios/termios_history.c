/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** history_exclamation
*/

#include <malloc.h>
#include <iso646.h>

#include "my/string.h"
#include "my/stdio.h"
#include "my/array.h"
#include "my/stdlib.h"

#include "enums.h"
#include "structure.h"

static bool last_command(char **input, minish_t *minish, bool realtime)
{
    unsigned index = 0;
    char *command = NULL;

    if (not ((realtime) ? my_strcmp(*input, "!! ") : my_strcmp(*input, "!!")))
        return false;
    index = history_lastnum(minish);
    command = history_getcommand(index - 1, minish);
    *input = my_superstrcat(2, command, " ");
    free(command);
    return true;
}

static char *get_start_command(char *starts_word, minish_t *minish)
{
    char **split = my_newarray(NULL);
    char *command = my_newstr(NULL);

    for (int n = my_arraylen((const char **)minish->history_parser);
    n > 0; --n) {
        free(command);
        my_arrayfree(split);
        command = history_getcommand(n - 1, minish);
        split = my_array_str(command);
        if (split == NULL or split[0] == NULL)
            continue;
        if (my_strcmp(split[0], starts_word))
            return command;
    }
    free(command);
    my_arrayfree(split);
    return NULL;
}

static bool str_start_command(char **input, minish_t *minish, bool realtime)
{
    char **split = my_array_str(*input);
    char *strcut = NULL;
    char *new_command = NULL;

    if (split == NULL || my_arraylen((const char **)split) != 1)
        return false;
    if (split[0][0] != '!' ||
    (realtime && (*input)[my_strlen(*input) - 1] != ' '))
        return false;
    strcut = my_strcut((const char *)split[0], 1, my_strlen(split[0]));
    new_command = get_start_command(strcut, minish);
    if (new_command == NULL)
        return false;
    *input = new_command;
    return true;
}

short termios_history(char **input, minish_t *minish, bool realtime)
{
    bool ret = false;

    ret = ((ret) ? ret : last_command(input, minish, realtime));
    ret = ((ret) ? ret : n_command(input, minish, realtime));
    ret = ((ret) ? ret : str_start_command(input, minish, realtime));
    return ret;
}
