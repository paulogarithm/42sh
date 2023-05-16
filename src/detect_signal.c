/*
** EPITECH PROJECT, 2023
** deteccte_signal.c
** File description:
** detecte the sifnal of the child for the project minishell  / semestre 2
*/

#include "structure.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

void my_puterror(char const *str)
{
    write(2, str, my_strlen_max(str));
}

static void detecte_signal_part_2
(minish_t *s, int core_dumped, int check, bool is_error)
{
    if (check == 8) {
        s->return_value = 136;
        my_puterror("Floating exception");
    }
    if (core_dumped)
        my_puterror(" (core dumped)");
    if (check == 0)
        s->return_value = 0;
    my_puterror(is_error ? "\n" : "");
}

void detect_signal(int status, minish_t *s)
{
    int core_dumped = 0;
    int check = 0;
    bool is_error = true;

    if (WIFSIGNALED(status)) {
        check = WTERMSIG(status);
        core_dumped = WCOREDUMP(status);
    }
    if (check == 11) {
        my_puterror("Segmentation fault");
        s->return_value = 139;
    } else if (check == 6) {
        s->return_value = 134;
        my_puterror("Abort");
    } else
        is_error = false;
    detecte_signal_part_2(s, core_dumped, check, is_error);
}
