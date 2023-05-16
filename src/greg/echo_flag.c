/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** all flag of echo
*/

#include "structure.h"
#include <string.h>
#include <stdio.h>
#include "my/stdio.h"
#include "tab.h"
#include "my/array.h"
#include <unistd.h>
#include "my/stdio.h"

int echo_pid(minish_t *minish)
{
    pid_t pid = getpid();

    my_printf("%d", pid);
    minish->return_value = 0;
    return 1;
}

int my_echo_enable_backslash(char **array, minish_t *minish)
{
    (void)array;
    minish->return_value = 0;
    return 1;
}

int my_echo_bin(char **array, minish_t *minish)
{
    (void)array;
    minish->return_value = 0;
    return 1;
}

int my_echo(char **array, minish_t *minish)
{
    if (my_arraylen((const char **)array) == 3 && strcmp(array[2], "\\") == 0)
        return echo_take_output(minish);
    if (my_arraylen((const char **)array) == 3 && strcmp(array[2], "$$") == 0)
        return echo_pid(minish);
    for (int i = 2; array[i] != NULL; i++) {
        my_printf("%s", array[i]);
        if (array[i + 1] != NULL)
            my_printf(" ");
    }
    minish->return_value = 0;
    return 1;
}

int my_echo_trailing_newline(char **array, minish_t *minish)
{
    my_basic_echo(array, minish);
    my_printf("\n");
    minish->return_value = 0;
    return 1;
}
