/*
** EPITECH PROJECT, 2023
** parser_ll.h
** File description:
** contain all struccture and linked_list for binary tree
*/

#include "structure.h"

#ifndef PARSER_LL_H_
    #define PARSER_LL_H_

// typedef binary_tree binary_tree_t;

struct binary_tree {
    char *data;
    struct binary_tree *right;
    struct binary_tree *left;
};

int parseur_function(minish_t *s, struct binary_tree *bt);

#endif /* !PARSER_LL_H_ */
