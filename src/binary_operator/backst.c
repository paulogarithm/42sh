/*
** EPITECH PROJECT, 2023
** backstick
** File description:
** epitech
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

char *backticks3(int o, int fd[2], char *buffi, char **buffs)
{
    char *cmd = NULL;
    wait(&o);
    dup2(0, STDIN_FILENO);
    close(fd[1]);
    read(fd[0], buffi, BUFSIZ);
    change(buffi);
    buffs[1] = buffi;
    cmd = tableau_to_string(buffs);
    close(fd[0]);
    return cmd;
}

char *backticks2(char **buffs, minish_t *s, struct binary_tree *bt)
{
    int o = 0;
    char *cmd = NULL;
    pid_t child_pid = 0;
    int fd[2];
    char *buffi = malloc(sizeof(char) * (BUFSIZ + 1));

    buffi[BUFSIZ] = '\0';
    pipe(fd);
    child_pid = fork();
    if (child_pid == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        bt = operation_priority(buffs[1], 0);
        o = parseur_function(s, bt);
        close(fd[1]);
    } else
        cmd = backticks3(o, fd, buffi, buffs);
    close(child_pid);
    free(buffi);
    return cmd;
}

char *backticks(char *command, int i, minish_t *s, struct binary_tree *bt)
{
    int is = 0;
    char *cmd = NULL;
    char **buffs = malloc(sizeof(char *) + (10));

    buffs[0] = malloc(sizeof(char) + (strlen(command)));
    buffs[1] = malloc(sizeof(char) + (1000));
    buffs[2] = NULL;
    for (int i = 0, is = 0; i < s->save_i - 1; i++, is++)
        buffs[0][is] = command[i];
    for (; s->save_i < i; s->save_i++) {
        if (command[s->save_i] != '`') {
            buffs[1][is] = command[s->save_i];
            is++;
        }
    }
    buffs[1][is] = '\0';
    cmd = backticks2(buffs, s, bt);
    return cmd;
}
