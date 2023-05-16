/*
** EPITECH PROJECT, 2023
** execution.c
** File description:
** execution the function of the parseur ll
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <iso646.h>

#include "my/string.h"
#include "my/array.h"

#include "structure.h"

static void execve_function(char *command, char *path, minish_t *minish)
{
    char **array = my_strsplit(command, " ");
    char *full_command = my_superstrcat(3, path, "/", array[0]);

    execve(full_command, array, minish->env);
    execve(array[0], array, minish->env);
    my_arrayfree(array);
    free(full_command);
}

static void loop_fork(minish_t *minish, char *commande, char *path_total)
{
    char **array = NULL;
    int status = 0;
    pid_t child_pid = fork();

    if (child_pid == 0) {
        array = my_strsplit(path_total, ":");
        for (int i = 0; array[i] != NULL; i += 1)
            execve_function(commande, array[i], minish);
        my_arrayfree(array);
        errno_function(commande);
        exit(1);
    }
    waitpid(child_pid, &status, 0);
    if (status > 255)
        status /= 256;
    minish->return_value = status;
    detect_signal(status, minish);
}

static int execute_array(minish_t *minish, char **array)
{
    char *command = my_strjoin((const char **)array, " ");
    char *str = get_envval((const char **)minish->env, "PATH");

    if (str == NULL)
        str = my_newstr("/bin:/usr/bin");
    loop_fork(minish, command, str);
    free(str);
    free(command);
    return 0;
}

int execution(char *command, minish_t *s)
{
    char **array = my_array_str(command);
    char **old = NULL;
    int res = 0;

    if (array == NULL || array[0] == NULL)
        return 0;
    if (replace_vaguelette(&array, (const char **)s->env)) {
        my_arrayfree(array);
        return 0;
    }
    old = my_newarray(NULL);
    res = res ? res : replace_alias(&array, s, old);
    res = res ? res : custom(&array, s);
    res = res ? res : execute_array(s, array);
    my_arrayfree(array);
    if (res == -1)
        return res;
    return 0;
}
