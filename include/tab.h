/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** all for associative tab
*/

#ifndef TAB_H_
    #define TAB_H_

    #include "structure.h"

typedef struct assosiative_echo_s {
    int (*function)(char **array, minish_t *minish);
    char *flag;
} assosiative_echo_t;

int my_echo_enable_backslash(char **array, minish_t *minish);
int my_echo_bin(char **array, minish_t *minish);
int my_echo(char **array, minish_t *minish);
int my_echo_trailing_newline(char **array, minish_t *minish);
int echo_pid(minish_t *minish);
int echo_take_output(minish_t *minish);

#endif /* !TAB_H_ */
