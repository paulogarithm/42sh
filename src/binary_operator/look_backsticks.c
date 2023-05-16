/*
** EPITECH PROJECT, 2023
** look_backsticks
** File description:
** 42sh
*/

#include "structure.h"
#include "parser_ll.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *tableau_to_string(char **buff)
{
    int i = 0;
    char *cmd = NULL;
    cmd = malloc(sizeof(char) + 10000);

    for (int x = 0; buff[x] != NULL; x++) {
        if (x != 0) {
            cmd[i] = ' ';
            i++;
        }
        for (int y = 0; buff[x][y] != '\0'; y++) {
            cmd[i] = buff[x][y];
            i++;
        }
    }
    return cmd;
}

char *change(char *buffi)
{
    for (int x = 0; buffi[x] != '\0'; x++) {
        if (buffi[x] == '\n' && buffi[x + 1] != '\0')
            buffi[x] = ' ';
        if (buffi[x] == '\n' && buffi[x + 1] == '\0')
            buffi[x] = '\0';
    }
    return buffi;
}

char *two_backsticks(int i, char *command, minish_t *s, struct binary_tree *bt)
{
    s->save_i = i;
    for (; command[i] != '\0'; i++) {
        if (command[i] == '`') {
            command = backticks(command, i, s, bt);
            s->save_i = i;
            return command;
        }
    }
    my_putstr_max("Unmatched '`'.\n");
    return command;
}

char *look_backsticks(char *command, minish_t *s, struct binary_tree *bt)
{
    if (command == NULL)
        return command;
    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '`') {
            command = two_backsticks(i + 1, command, s, bt);
            i = s->save_i;
        }
    }
    return command;
}
