/*
** EPITECH PROJECT, 2023
** double_esperluette.c
** File description:
** double_esperluette
*/

#include "structure.h"
#include "parser_ll.h"
#include <stdio.h>
#include "my/stdio.h"

void double_esperluette(minish_t *s, struct binary_tree *bt)
{
    if (bt->right != NULL && bt->right->data[0] == 0) {
        my_printf("Invalid null command.\n");
        return;
    }
    if (bt->left != NULL) {
        parseur_function(s, bt->left);
    }
    if (bt->right != NULL && s->return_value == 0) {
        parseur_function(s, bt->right);
    }
}
