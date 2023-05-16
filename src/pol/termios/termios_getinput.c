/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** termios_classic
*/

#include <stdio.h>
#include <malloc.h>

#include "structure.h"
#include "my/string.h"

static void my_remcharindex(char **str, const size_t index)
{
    char *new = malloc(sizeof(char));

    if (new == NULL)
        return;
    new[0] = '\0';
    for (size_t n = 0; (*str)[n] != '\0'; n ++) {
        if (n == index)
            continue;
        my_addchar(&new, (*str)[n]);
    }
    free(*str);
    *str = new;
}

short int termios_getinput
(char **input, int *cursorpos, long *historypos, minish_t *minish)
{
    char c = getchar();

    switch (c) {
    case '\n':
        return 1;
    case '\033':
        return termios_arrow(input, cursorpos, minish, historypos);
    case '\t':
        return termios_tab(input, minish);
    case 127:
        my_remcharindex(input, my_strlen(*input) - *cursorpos - 1);
            return 0;
    case 4:
        return -1;
    default:
        my_addcharindex(input, c, (my_strlen(*input) - (*cursorpos)));
        return 0;
    }
    return 1;
}
