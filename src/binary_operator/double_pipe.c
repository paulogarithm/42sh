/*
** EPITECH PROJECT, 2023
** double_pipe.c
** File description:
** double_pipe
*/

#include "structure.h"
#include "parser_ll.h"
#include <stdio.h>
#include "my/stdio.h"

void double_pipe(minish_t *s, struct binary_tree *bt)
{
    if (bt->right != NULL && bt->right->data[0] == 0) {
        my_printf("Invalid null command.\n");
        return;
    }
    if (bt->left != NULL && bt->left->data[0] == 0) {
        my_printf("Invalid null command.\n");
        return;
    }
    if (bt->left != NULL) {
        parseur_function(s, bt->left);
    }
    if (bt->right != NULL && s->return_value != 0) {
        parseur_function(s, bt->right);
    }
}
