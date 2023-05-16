/*
** EPITECH PROJECT, 2023
** infinite_loop.c
** File description:
** start the boucle inf for the project minishell1 / semestre 2
*/

#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <malloc.h>
#include <unistd.h>

#include "structure.h"
#include "parser_ll.h"

int call_binary_tree(minish_t *s, struct binary_tree *bt, char *command)
{
    if (command[0] != 0) {
        command = strtok(command, "\n");
        bt = operation_priority(command, 0);
        if (parseur_function(s, bt) == -1)
            return -1;
    }
    return 0;
}

static unsigned short loop_action
(minish_t *s, char **command, struct binary_tree *bt, const bool is_empty)
{
    int status = 0;

    signal(SIGTSTP, is_pause);
    signal(SIGINT, nothing);
    *command = ((isatty(STDIN_FILENO)) ? termios_scanf(get_show(
        is_empty, s), &status, s) : my_getlinescanf("", &status));
    if (status == -1)
        return 1;
    *command = look_backsticks(*command, s, bt);
    if (*command == NULL)
        return 0;
    write_hs(*command, s);
    if (grof(*command, s))
        return 0;
    if (call_binary_tree(s, bt, *command) == -1)
        return 2;
    return 0;
}

void infinite_loop(minish_t *s, const bool is_empty)
{
    struct binary_tree *bt = NULL;
    char *command = malloc(sizeof(1));
    int action = 0;

    while (1) {
        free(command);
        action = loop_action(s, &command, bt, is_empty);
        if (action == 1)
            break;
        if (action == 2) {
            free(command);
            return;
        }
    }
    free(command);
    my_putstr_max((isatty(STDIN_FILENO)) ? "exit\n" : "");
}
