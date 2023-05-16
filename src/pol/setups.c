/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** setups
*/

#include <malloc.h>
#include <termios.h>
#include <unistd.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "enums.h"
#include "structure.h"

minish_t *setup_minishell(char **env, char *absolute)
{
    minish_t *minishell = malloc(sizeof(minish_t));

    if (minishell == NULL)
        return NULL;
    minishell->absolute = absolute;
    minishell->env = my_newarray((const char **)env);
    minishell->previous_path = my_newstr("");
    minishell->aliases = malloc(sizeof(char *));
    if (minishell->aliases == NULL)
        return NULL;
    minishell->aliases[0] = NULL;
    minishell->history_parser = my_array_parsing(FILE_HS);
    if (minishell->history_parser == NULL) {
        minishell->history_parser = malloc(sizeof(char *));
        minishell->history_parser[0] = NULL;
    }
    minishell->return_value = 0;
    return minishell;
}

termios_t *termios_setup(void)
{
    termios_t *termios = malloc(sizeof(termios_t));

    tcgetattr(STDIN_FILENO, &termios->saved);
    termios->t = termios->saved;
    termios->t.c_lflag = termios->t.c_lflag & ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &termios->t);
    return termios;
}
