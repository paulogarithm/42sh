/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** linked_list
*/

#ifndef LINKED_H
    #define LINKED_H

typedef struct cell_s {
    char *str;
    struct cell_s *next;
} cell_t;

typedef struct list_s {
    cell_t *head;
} list_t;

#endif
