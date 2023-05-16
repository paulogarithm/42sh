/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** termios_tab
*/

#include <stddef.h>
#include <malloc.h>

#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "structure.h"

static char **get_root(const char *str)
{
    char **ret = my_newarray(NULL);
    const char *brakes = "./~";
    long n = -1;
    char *tmp = NULL;

    if (my_strcfnd(brakes, str[0]) < 0)
        return NULL;
    for (; n < ((long)my_strlen(str) - 1); ++n)
        if (my_strcfnd(brakes, str[n + 1]) < 0)
            break;
    tmp = my_strcut(str, 0, n + 1);
    my_arrayadd(&ret, tmp);
    free(tmp);
    tmp = my_strcut(str, n + 1, my_strlen(str));
    my_arrayadd(&ret, tmp);
    free(tmp);
    return ret;
}

static char **get_files(const char *input)
{
    const char **usefull = (const char **)get_root(input);
    char **files = NULL;

    if (usefull == NULL) {
        files = get_allfiles("/bin/", false);
        files = my_filter_startswith(files, input);
        return files;
    }
    files = get_allfiles(usefull[0], false);
    files = my_filter_startswith(files, usefull[1]);
    for (size_t n = 0; files[n] != NULL; n ++)
        files[n] = my_superstrcat(2, usefull[0], files[n]);
    return files;
}

static bool tab_command(char **input, minish_t *minish)
{
    char **files = get_files((const char *)(*input));

    (void)minish;
    if (my_arraylen((const char **)files) == 0)
        return 0;
    if (my_arraylen((const char **)files) == 1) {
        *input = my_superstrcat(1, files[0]);
        my_arrayfree(files);
        return 0;
    }
    my_printf("%a\n", files);
    return 0;
}

static bool tab_none(minish_t *minish)
{
    return execution("/bin/ls -F", minish);
}

bool termios_tab(char **input, minish_t *minish)
{
    char **split = NULL;

    my_printf("\n");
    if (my_strlen(*input) == 0)
        return tab_none(minish);
    split = my_array_str(*input);
    if (split == NULL || split[0] == NULL)
        return 1;
    if (my_arraylen((const char **)split) == 1)
        return tab_command(input, minish);
    my_addstr(input, "Tab");
    return 0;
}
