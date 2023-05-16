/*
** EPITECH PROJECT, 2023
** globbing
** File description:
** epitech
*/


#include "structure.h"
#include "parser_ll.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <glob.h>

static void glob_ex(char **buff, int i, char *commande)
{
    pid_t child_pid = 0;
    glob_t globbuf;

    child_pid = fork();
    if (child_pid == 0) {
        globbuf.gl_offs = i - 1;
        glob(commande, GLOB_DOOFFS, NULL, &globbuf);
        for (int is = 0; is < i - 1; is++) {
            globbuf.gl_pathv[is] = buff[is];
        }
        execvp(buff[0], &globbuf.gl_pathv[0]);
    }
    waitpid(child_pid, NULL, 0);
    close(child_pid);
}

static char *rm_space(char *buff)
{
    char *commande2 = malloc(sizeof(char) * (1000));

    for (int i = 0, r = 0, k = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ')
            r++;
        if (r != 0) {
            commande2[k] = buff[i];
            k++;
        }
    }
    return commande2;
}

void globbing(minish_t UNUSED *s, struct binary_tree *bt)
{
    char **buff = NULL;
    char *commande = malloc(sizeof(char) * (1000));
    int i = 0;
    char *commande2 = rm_space(bt->left->data);

    buff = my_str_to_word_array_max(commande2, ' ');
    for (; buff[i] != NULL; i++);
    if (bt->right->data[0] == '*' || bt->right->data[0] == 0) {
        commande = buff[i - 1];
        strcat(commande, bt->data);
    } else {
        commande = bt->data;
        strcat(commande, bt->right->data);
    }
    glob_ex(buff, i, commande);
    free(commande);
}
