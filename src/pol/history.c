/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** history
*/

#include <unistd.h>
#include <malloc.h>
#include <iso646.h>
#include "my/string.h"
#include "my/stdio.h"
#include "my/array.h"
#include "my/stdlib.h"

#include "enums.h"
#include "structure.h"

unsigned int history_lastnum(minish_t *minish)
{
    char *path = NULL;
    char **array = NULL;
    char *last_line = NULL;
    int num = 0;

    if (minish->absolute == NULL)
        return 0;
    path = my_superstrcat(3, minish->absolute, "/", FILE_HS);
    array = my_array_parsing(path);
    if (array == NULL or array[0] == NULL or my_strlen(array[0]) == 0
    or access(path, R_OK))
        return 0;
    last_line = array[my_arraylen((const char **)array) - 1];
    free(array);
    array = my_array_str(last_line);
    if (array == NULL or array[0] == NULL)
        return 0;
    num = my_atoi(array[0]);
    return num;
}

char *history_getcommand(int pos, minish_t *minish)
{
    char *line = my_newstr(minish->history_parser[pos]);
    char **array = my_array_str(line);

    if (array == NULL or array[0] == NULL)
        return NULL;
    my_arraypop(&array, 0);
    free(line);
    line = my_strjoin((const char **)array, " ");
    free(array);
    return line;
}

char *history_setcommand(char *command, minish_t *minish)
{
    unsigned int index = history_lastnum(minish);
    char **array = NULL;
    char *ret = NULL;

    if (command == NULL or my_strlen(command) == 0)
        return NULL;
    array = my_newarray(NULL);
    index += 1;
    my_arrayadd(&array, my_itoa(index));
    my_arrayadd(&array, command);
    ret = my_strjoin((const char **)array, " ");
    my_arrayfree(array);
    return ret;
}
