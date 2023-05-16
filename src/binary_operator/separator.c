/*
** EPITECH PROJECT, 2023
** separator.c
** File description:
** separator
*/

#include "structure.h"
#include "parser_ll.h"
#include <stdio.h>

void separator(minish_t *s, struct binary_tree *bt)
{
    if (bt->left != NULL) {
        parseur_function(s, bt->left);
    }
    if (bt->right != NULL) {
        parseur_function(s, bt->right);
    }
}
