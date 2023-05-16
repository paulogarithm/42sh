/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** echo building
*/

#include <string.h>
#include <stdio.h>
#include "tab.h"
#include "my/stdio.h"
#include "my/array.h"
#include "structure.h"

static const assosiative_echo_t FUNCS[] =
{
    { my_echo, "-n" },
    { my_echo, "-ne" },
    { my_echo, "-en" },
    { my_echo, "-nE" },
    { my_echo, "-En" },
    { my_echo_enable_backslash, "-e" },
    { my_echo_trailing_newline, "-E" },
    { my_echo_bin, "--help" },
    { my_echo_bin, "--version" },
    { NULL, NULL }
};

int echo_take_output(minish_t *minish)
{
    size_t len = 32000;
    char *str = NULL;

    my_printf("> ");
    getline(&str, &len, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmp(str, "$?") == 0)
        my_printf("%d", minish->return_value);
    else
        my_printf("%s", str);
    minish->return_value = 0;
    return 1;
}

int my_basic_echo(char **array, minish_t *minish)
{
    if (my_arraylen((const char **)array) == 2 && strcmp(array[1], "\\") == 0)
        return echo_take_output(minish);
    if (my_arraylen((const char **)array) == 2 && strcmp(array[1], "$$") == 0)
        return echo_pid(minish);
    for (int i = 1; array[i] != NULL; i++) {
        my_printf("%s", array[i]);
        if (array[i + 1] != NULL)
            my_printf(" ");
    }
    minish->return_value = 0;
    return 1;
}

static int echo_flag(char **array_cmd, minish_t *minish)
{
    for (int i = 0; FUNCS[i].flag != NULL; i++)
        if (strcmp(array_cmd[1], FUNCS[i].flag) == 0)
            return FUNCS[i].function(array_cmd, minish);
    my_echo_trailing_newline(array_cmd, minish);
    minish->return_value = 0;
    return 1;
}

static int simple_echo(minish_t *minish)
{
    my_printf("\n");
    minish->return_value = 0;
    return 1;
}

int custom_echo(char **array_cmd, minish_t *minish)
{
    if (strcmp(array_cmd[0], "echo") != 0)
        return 0;
    if (strcmp(array_cmd[0], "echo") == 0
    && my_arraylen((const char **)array_cmd) == 1)
        return simple_echo(minish);
    else
        return echo_flag(array_cmd, minish);
}
