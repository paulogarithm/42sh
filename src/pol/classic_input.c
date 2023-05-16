/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** misc_scnaf
*/

#include <stdlib.h>
#include <stdio.h>
#include "my/string.h"
#include "my/stdio.h"

#include "structure.h"

char *my_getlinescanf(char *show, int *status)
{
    long unsigned int size = 0;
    char *command = NULL;
    char last = '\0';
    int count = 0;
    char *ret = NULL;

    my_printf(show);
    *status = getline(&command, &size, stdin);
    if (*status == -1) {
        free(command);
        return NULL;
    }
    count = my_strlen(command) - 1;
    last = command[count];
    ret = ((last == '\n') ? my_strcut(command, 0, count) : my_newstr(command));
    free(command);
    return my_strlen(ret) == 0 ? NULL : ret;
}
