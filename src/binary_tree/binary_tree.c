/*
** EPITECH PROJECT, 2023
** binary_tree.c
** File description:
** form a binary tree of function
*/

#include "structure.h"
#include "parser_ll.h"
#include <stdlib.h>

struct binary_tree *operation_priority(char *cmd, int priority_level);

int is_operateur(char *str, int weight)
{
    char *light[] = {";", "&&", "||", NULL};
    char *heavy[] = {"<<", ">>", "<", ">", "|", "*", "?", NULL};
    char **list[] = {light, heavy, NULL};
    if (weight >= 2) {
        return -1;
    }
    for (int i = 0; list[weight][i] != NULL; i += 1) {
        if (!my_strncmp_max(list[weight][i],
        str, my_strlen_max(list[weight][i]) - 1)) {
            return my_strlen_max(list[weight][i]);
        }
    }
    return -1;
}

struct binary_tree *build_tree
(char *data, struct binary_tree *left, struct binary_tree *right)
{
    struct binary_tree *tree = malloc(sizeof(struct binary_tree));

    tree->left = left;
    tree->right = right;
    tree->data = data;
    return tree;
}

static void rebuild_under_tree(struct binary_tree *tree, int priority)
{
    int root = 0;
    if (tree->left != NULL) {
        root = 1;
        rebuild_under_tree(tree->left, priority);
    }
    if (tree->right != NULL) {
        root = 1;
        rebuild_under_tree(tree->right, priority);
    }
    if (!root) {
        struct binary_tree *new_tree = operation_priority(tree->data, priority);
        if (new_tree == NULL) {
            return;
        }
        tree->data = new_tree->data;
        tree->left = new_tree->left;
        tree->right = new_tree->right;
        free(new_tree);
    }
}

void place_the_end_of_cmd(int i, char **cmd, int operateur)
{
    for (int j = 0; j < operateur; j += 1) {
        (*cmd)[i + j] = '\0';
    }
}

struct binary_tree *operation_priority(char *cmd, int priority_level)
{
    char *current_array = NULL;
    int operateur = -1;
    struct binary_tree *tmp = build_tree(cmd, NULL, NULL);

    if (priority_level >= 2)
        return NULL;
    for (int i = 0; cmd[i] != '\0'; i += 1) {
        operateur = is_operateur(cmd + i, priority_level);
        if (operateur != -1) {
            current_array = my_strndup_max(cmd + i, operateur);
            tmp = build_tree
            (current_array, tmp, build_tree(cmd + i + operateur, NULL, NULL));
            place_the_end_of_cmd(i, &cmd, operateur);
            cmd += i + my_strlen_max(current_array);
            i = 0;
        }
    }
    rebuild_under_tree(tmp, priority_level + 1);
    return tmp;
}
