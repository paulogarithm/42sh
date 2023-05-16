/*
** EPITECH PROJECT, 2023
** sub_main.c
** File description:
** sub main for the project minishell1 / semestre 2
*/

#include <malloc.h>
#include <iso646.h>
#include "my/array.h"

#include "structure.h"

static void minishend(minish_t *minish)
{
    if (minish->absolute != NULL)
        free(minish->absolute);
    free(minish->previous_path);
    my_arrayfree(minish->aliases);
    my_arrayfree(minish->env);
    my_arrayfree(minish->history_parser);
    free(minish);
}

int sub_main(int ac, char **av, char **env)
{
    char *absolute = get_absolutepath(av[0]);
    minish_t *s = setup_minishell(env, absolute);
    int return_value = 0;

    if (s == NULL or ac != 1)
        return 84;
    read_rc(s);
    infinite_loop(s, env[0] == NULL);
    return_value = s->return_value;
    minishend(s);
    return return_value;
}
