/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** reading
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iso646.h>
#include <sys/stat.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "structure.h"
#include "enums.h"

void read_rc(minish_t *minish)
{
    char *path = my_newstr(minish->absolute);
    char **parsing = NULL;

    if (my_strlen(path) == 0)
        return;
    my_addchar(&path, '/');
    my_addstr(&path, FILE_RC);
    parsing = my_array_parsing(path);
    if (parsing == NULL)
        return;
    for (int n = 0; parsing[n] != NULL; n ++) {
        if (parsing[n][0] == '#')
            continue;
        execution(parsing[n], minish);
    }
}

static bool no_writable(const char *command, minish_t *minish)
{
    unsigned last_num = history_lastnum(minish);
    if (last_num == 0)
        return false;
    char *last_command = history_getcommand(last_num - 1, minish);

    if (my_strcmp(last_command, command))
        return true;
    if (command[0] == '!')
        return true;
    return false;
}

void write_hs(char *command, minish_t *minish)
{
    int flags = O_WRONLY | O_CREAT | O_APPEND;
    char *path = NULL;
    char *dup = history_setcommand(command, minish);
    int fd = 0;

    if (command == NULL or dup == NULL or no_writable(command, minish)
    or minish->absolute == NULL)
        return;
    path = my_superstrcat(3, minish->absolute, "/", FILE_HS);
    fd = open(path, flags, 0644);
    if (fd < 0)
        return;
    my_addchar(&dup, '\n');
    write(fd, dup, my_strlen(dup) * sizeof(char));
    my_arrayfree(minish->history_parser);
    free(dup);
    minish->history_parser = my_array_parsing(path);
    close(fd);
}

int get_filemode(char *path, int mode)
{
    struct stat st;

    if (path == NULL)
        return 1;
    if (stat(path, &st) == -1)
        return -1;
    if (S_ISREG(st.st_mode))
        return !(mode == M_REG);
    if (S_ISDIR(st.st_mode))
        return !(mode == M_DIR);
    return 1;
}
