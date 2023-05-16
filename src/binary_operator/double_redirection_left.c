/*
** EPITECH PROJECT, 2023
** double_redirection_left.c
** File description:
** manage the double_redirection_left / project 42sh
*/

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "parser_ll.h"
#include "structure.h"
#include "linked_list.h"

int print_the_list(list_t *list_words)
{
    cell_t *temp = list_words->head;

    if (temp == NULL)
        return 0;
    while (temp != NULL) {
        printf("%s\n", temp->str);
        temp = temp->next;
    }
    return 0;
}

int add_to_list(list_t *list_words, char *str)
{
    cell_t *temp = list_words->head;
    cell_t *new = malloc(sizeof(cell_t));

    new->str = strdup(str);
    new->next = NULL;

    if (temp == NULL) {
        list_words->head = new;
        return 0;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    return 0;
}

int linked_list(char *end)
{
    list_t *list_words = malloc(sizeof(list_t));
    size_t len = 32000;
    char *str = NULL;

    list_words->head = NULL;
    printf("? ");
    while ((getline(&str, &len, stdin) != -1)) {
        str[strlen(str) - 1] == '\n' ? str[strlen(str) - 1] = '\0' : 0;
        if (strcmp(str, end) == 0)
            break;
        printf("? ");
        add_to_list(list_words, str);
    }
    print_the_list(list_words);
    free(list_words);
    free(str);
    return 0;
}

void double_redirection_left(minish_t *s, struct binary_tree *bt)
{
    s->return_value = linked_list(formatting_str(bt->right->data));
    return;
}
