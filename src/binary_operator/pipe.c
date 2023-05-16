/*
** EPITECH PROJECT, 2023
** pipe.c
** File description:
** function for the pipe
*/

#include "structure.h"
#include "parser_ll.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void pipe_function_fork_number_2(minish_t *s, struct binary_tree *bt,
int *fd, pid_t child_pid)
{
    pid_t child_pid_2 = 0;

    child_pid_2 = fork();
    if (child_pid_2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        parseur_function(s, bt->right);
        exit(0);
    }
    close(fd[0]);
    waitpid(child_pid, NULL, 0);
    waitpid(child_pid_2, NULL, 0);
}

void pipe_function(minish_t *s, struct binary_tree *bt)
{
    pid_t child_pid = 0;
    int fd[2];

    if (pipe(fd) == -1)
        return;
    child_pid = fork();
    if (child_pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        parseur_function(s, bt->left);
        exit(0);
    }
    close(fd[1]);
    pipe_function_fork_number_2(s, bt, fd, child_pid);
}
