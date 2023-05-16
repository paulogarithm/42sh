/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** termios_arrays
*/

#include <stdio.h>
#include <unistd.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdlib.h"

#include "structure.h"

static bool move_cursor(const char c, int *cursorpos)
{
    *cursorpos += ((c == 'C') ? -1 : 1);
    return 0;
}

static bool move_history
(char c, long *hpos, char **input, minish_t *minish)
{
    *hpos += (c == 'B') ? 1 : -1;
    *hpos = my_max(*hpos, 0);
    if (*hpos > (ssize_t)my_arraylen((const char **)minish->history_parser))
        *hpos -= 1;
    *input =
        (*hpos == (ssize_t)my_arraylen((const char **)minish->history_parser)) ?
        my_newstr(NULL) : history_getcommand((int)(*hpos), minish);
    return 0;
}

static bool move_radical(char c, const char *input, int *cursorpos)
{
    if (c == 'H')
        *cursorpos = my_strlen(input);
    if (c == 70)
        *cursorpos = 0;
    return 0;
}

short termios_arrow
(char **input, int *cursorpos, minish_t *minish, long *historypos)
{
    char *keys = my_newstr(NULL);

    my_addchar(&keys, getchar());
    my_addchar(&keys, getchar());
    if (keys[0] != '[')
        return 0;
    switch (keys[1]) {
        case 'A':
        case 'B':
        return move_history(keys[1], historypos, input, minish);
        case 'C':
        case 'D':
        return move_cursor(keys[1], cursorpos);
        case 'H':
        case 70:
        return move_radical(keys[1], *input, cursorpos);
        default:
        return 0;
    }
}
