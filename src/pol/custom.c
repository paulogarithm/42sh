/*
** EPITECH PROJECT, 2023
** sh_re
** File description:
** custom
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "enums.h"
#include "structure.h"

static int custom_exit(char **array)
{
    if (array[0] == NULL)
        return 1;
    if (my_strcmp(array[0], "exit")) {
        my_printf(isatty(STDIN_FILENO) ? "exit\n" : "");
        return -1;
    }
    return 0;
}

static int custom_cd_special(char ***array, char **env, char **previous_path)
{
    char *val = NULL;

    if ((*array)[1] != NULL && my_strcmp((*array)[1], "-")) {
        free((*array)[1]);
        (*array)[1] = my_newstr(*previous_path);
        return 0;
    }
    val = get_envval((const char **)env, "HOME");
    if (val == NULL)
        return 1;
    my_arrayadd(array, val);
    free(val);
    return 0;
}

static int custom_cd(char ***array, char **env, char **previous_path)
{
    int folder_res = 0;

    if (!my_strcmp((*array)[0], "cd"))
        return 0;
    if (my_arraylen((const char **)*array) > 2)
        return my_printf("cd: Too many arguments.\n");
    if (my_arraylen((const char **)*array) == 1 || my_strcmp((*array)[1], "-"))
        if (custom_cd_special(array, env, previous_path))
            return my_printf("cd: No home directory.\n");
    folder_res = get_filemode((*array)[1], M_DIR);
    if (folder_res)
        return my_printf("%s: %s\n", (*array)[1],
        (folder_res < 1) ? "No such file or directory." : "Not a directory.");
    free(*previous_path);
    *previous_path = getcwd(NULL, 0);
    if (*previous_path == NULL)
        return my_printf("cd: getcwd error.\n");
    if (chdir((*array)[1]) == -1)
        return my_printf("cd: chdir error.\n");
    return 1;
}

static short custom_display_history(const char **command, minish_t *minish)
{
    if (command == NULL || command[0] == NULL ||
    not my_strcmp(command[0], "history"))
        return 0;
    my_arraydisp((const char **)minish->history_parser);
    return 1;
}

int custom(char ***array, minish_t *minish)
{
    int res = 0;

    res = res ? res : custom_alias(*array, minish);
    res = res ? res : custom_unalias((const char **)(*array), minish);
    replace_var(*array, minish);
    res = res ? res : custom_exit(*array);
    res = res ? res : custom_cd(array, minish->env, &minish->previous_path);
    res = res ? res : custom_setenv(*array, &minish->env);
    res = res ? res : custom_unsetenv(*array, &minish->env);
    res = res ? res : custom_display_history((const char **)(*array), minish);
    res = res ? res : custom_echo(*array, minish);
    return res;
}
