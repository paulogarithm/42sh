/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** alias
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"
#include "enums.h"
#include "structure.h"

int get_alias_pos(char **array, const char *str)
{
    char **split = NULL;

    for (int n = 0; array[n] != NULL; n++) {
        split = my_array_str(array[n]);
        if (split == NULL) {
            my_arrayfree(split);
            return -1;
        }
        if (my_strcmp(str, split[0])) {
            my_arrayfree(split);
            return n;
        }
        my_arrayfree(split);
    }
    return -1;
}

static char **get_banned_alias(void)
{
    char **BANNED_ALIASES = my_newarray(NULL);

    my_arrayadd(&BANNED_ALIASES, "alias");
    my_arrayadd(&BANNED_ALIASES, "unalias");
    return BANNED_ALIASES;
}

static int create_alias(char **array, minish_t *minish)
{
    char **BANNED_ALIASES = get_banned_alias();
    char *line = NULL;
    char **dup = NULL;
    int pos = 0;

    if (my_arrayindex((const char **)BANNED_ALIASES, array[1]) >= 0) {
        my_arrayfree(BANNED_ALIASES);
        return my_printf("alias: Too dangerous to alias that.\n");
    }
    my_arrayfree(BANNED_ALIASES);
    dup = my_newarray((const char **)array);
    my_arraypop(&dup, 0);
    line = my_strjoin((const char **)dup, " ");
    pos = get_alias_pos(minish->aliases, (const char *)array[1]);
    if (pos >= 0)
        my_arraypop(&minish->aliases, pos);
    my_arrayfree(dup);
    my_arrayadd(&minish->aliases, line);
    free(line);
    return 1;
}

int replace_alias(char ***array, minish_t *minish, char **old)
{
    char **new_array = NULL;
    char *new_command = NULL;
    int pos = get_alias_pos(minish->aliases, (const char *)(*array)[0]);
    bool is_same = false;

    if (pos < 0)
        return 0;
    new_command = my_newstr(minish->aliases[pos]);
    new_array = my_array_str(new_command);
    is_same = my_strcmp(new_array[0], new_array[1]);
    if (get_alias_pos(old, (const char *)new_array[0]) >= 0 && !is_same)
        return my_printf("Alias loop\n");
    my_arrayadd(&old, new_array[0]);
    my_arraypop(&new_array, 0);
    my_arraypop(array, 0);
    new_array = my_arraycat(new_array, *array);
    free(*array);
    free(new_command);
    *array = new_array;
    return is_same ? 0 : replace_alias(array, minish, old);
}

short custom_alias(char **array, minish_t *minish)
{
    int index = 0;

    if (array[0] == NULL || !my_strcmp(array[0], "alias"))
        return 0;
    switch (my_arraylen((const char **)array)) {
        case 1:
        my_arraydisp((const char **)minish->aliases);
        return 1;
        case 2:
        index = get_alias_pos(minish->aliases, (const char *)array[1]);
        if (index >= 0)
            my_printf("%s\n", minish->aliases[index]);
        return 1;
        break;
        default:
        return create_alias(array, minish);
    }
    return 0;
}
