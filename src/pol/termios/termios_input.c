/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** termios_scanf
*/

#include <unistd.h>
#include <malloc.h>
#include <stdio.h>
#include <iso646.h>

#include "structure.h"
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"
#include "my/stdlib.h"

static const char *KEYWORDS[] = {
    "exp",
    "for",
    "do",
    "end",
    NULL
};

static char *get_display(char *str)
{
    char **words = NULL;
    char *tmp = NULL;

    if (str == NULL)
        return my_newstr(NULL);
    words = my_array_str(str);
    for (size_t n = 0; words[n] != NULL; ++n) {
        if (my_arrayindex(KEYWORDS, words[n]) < 0)
            continue;
        tmp = my_superstrcat(4, "\033[31;1m", words[n], "\033[m");
        free(words[n]);
        words[n] = tmp;
    }
    return my_strjoin((const char **)words, " ");
}

static void termios_showing
(char *input, const char *showing, int *cursor_pos, int status)
{
    char *display = my_newstr(input);
    int num = my_strlen(display) + 100 + (status != 0);

    (void)get_display;
    if (input != NULL)
        my_printf("\033[%dD", num, num);
    my_printf("\033[0K");
    my_printf("%s%s", showing, display);
    *cursor_pos = my_max((*cursor_pos), 0);
    *cursor_pos = my_min((*cursor_pos), my_strlen(display));
    if (*cursor_pos)
        my_printf("\033[%dD", *cursor_pos);
    free(display);
}

static char *termios_loop(const char *showing, int *status, minish_t *minish)
{
    char *input = my_newstr(NULL);
    int cursorpos = 0;
    long historypos = my_arraylen((const char **)minish->history_parser);

    termios_showing(NULL, showing, &cursorpos, *status);
    while (*status == 0) {
        *status = termios_getinput(&input, &cursorpos, &historypos, minish);
        termios_history(&input, minish, true);
        termios_showing(input, showing, &cursorpos, *status);
    }
    return input;
}

char *termios_scanf(const char *showing, int *status, minish_t *minish)
{
    termios_t *termios = termios_setup();
    char *input = NULL;

    input = termios_loop(showing, status, minish);
    tcsetattr(STDIN_FILENO, TCSANOW, &termios->saved);
    if (*status >= 0)
        my_printf("\n");
    free(termios);
    return input;
}
