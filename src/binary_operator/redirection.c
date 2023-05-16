/*
** EPITECH PROJECT, 2023
** redirection.c
** File description:
** redirection functions for the project minish2
*/

#include "structure.h"
#include "parser_ll.h"
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void redirection_left(minish_t *s, struct binary_tree *bt)
{
    int file = 0;
    char *name_of_the_file = NULL;
    pid_t child_pid = 0;

    if (bt->right->data != NULL)
        name_of_the_file = strtok(bt->right->data, " ");
    file = open(name_of_the_file, O_RDONLY, 0);
    if (file == -1)
        return;
    child_pid = fork();
    if (child_pid == 0) {
        dup2(file, STDIN_FILENO);
        parseur_function(s, bt->left);
        close(file);
        exit(0);
    } else {
        waitpid(child_pid, NULL, 0);
        close(file);
    }
}

void redirection_right(minish_t *s, struct binary_tree *bt)
{
    int file = 0;
    char *name_of_file = NULL;
    pid_t child_pid = 0;

    if (bt->right->data != NULL)
        name_of_file = strtok(bt->right->data, " ");
    file = open(name_of_file, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
    if (file == -1)
        return;
    child_pid = fork();
    if (child_pid == 0) {
        dup2(file, STDOUT_FILENO);
        parseur_function(s, bt->left);
        close(file);
        exit(0);
    } else {
        waitpid(child_pid, NULL, 0);
    }
}

void double_redirection_right(minish_t *s, struct binary_tree *bt)
{
        int file = 0;
    char *name_of_file = NULL;
    pid_t child_pid = 0;

    if (bt->right->data != NULL)
        name_of_file = strtok(bt->right->data, " ");
    file = open(name_of_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file == -1)
        return;
    child_pid = fork();
    if (child_pid == 0) {
        dup2(file, STDOUT_FILENO);
        parseur_function(s, bt->left);
        close(file);
        exit(0);
    } else {
        waitpid(child_pid, NULL, 0);
    }
}
