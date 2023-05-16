/*
** EPITECH PROJECT, 2023
** errno.c
** File description:
** errno
*/

#include "structure.h"
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

void errno_function(char *command)
{
    pid_t child_pid = fork();
    char **array_cmd = my_array_str(command);

    free(command);
    command = my_newstr(array_cmd[0]);
    my_arrayfree(array_cmd);
    if (child_pid == 0) {
        if (errno == 2)
            my_printf("%s: Command not found.\n", command);
        if (errno == ENOEXEC)
            my_printf("%s: Exec format error. Wrong Architecture.\n", command);
        if (errno == EACCES)
            my_printf("%s: Permission denied.\n", command);
        exit(1);
    } else
        waitpid(child_pid, NULL, 0);
}
