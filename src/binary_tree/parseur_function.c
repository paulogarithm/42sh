/*
** EPITECH PROJECT, 2023
** parseur_function.c
** File description:
** function for parse the binary tree
*/

#include "structure.h"
#include "parser_ll.h"

static int parseur_funciton_second_part2(minish_t *s, struct binary_tree *bt)
{
    if (my_strcmp_max(bt->data, "*") == 0 ||
        my_strcmp_max(bt->data, "?") == 0) {
        globbing(s, bt);
        return 0;
    }
    return 0;
}

static int parseur_funciton_second_part(minish_t *s, struct binary_tree *bt)
{
    if (my_strcmp_max(bt->data, "||") == 0) {
        double_pipe(s, bt);
        return 0;
    }
    if (my_strcmp_max(bt->data, "<<") == 0) {
        double_redirection_left(s, bt);
        return 0;
    }
    if (my_strcmp_max(bt->data, ">>") == 0) {
        double_redirection_right(s, bt);
        return 0;
    }
    if (my_strcmp_max(bt->data, ">") == 0) {
        redirection_right(s, bt);
        return 0;
    }
    parseur_funciton_second_part2(s, bt);
    if (execution(bt->data, s) == -1)
        return -1;
    return 0;
}

int parseur_function(minish_t *s, struct binary_tree *bt)
{
    if (my_strcmp_max(bt->data, ";") == 0) {
        separator(s, bt);
        return 0;
    }
    if (my_strcmp_max(bt->data, "|") == 0) {
        pipe_function(s, bt);
        return 0;
    }
    if (my_strcmp_max(bt->data, "<") == 0) {
        redirection_left(s, bt);
        return 0;
    }
    if (my_strcmp_max(bt->data, "&&") == 0) {
        double_esperluette(s, bt);
        return 0;
    }
    if (parseur_funciton_second_part(s, bt) == -1)
        return -1;
    return 0;
}
