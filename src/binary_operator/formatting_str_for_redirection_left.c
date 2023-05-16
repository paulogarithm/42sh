/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** formatting str
*/

#include "structure.h"
#include <stdlib.h>
#include <string.h>

int nb_spaces(char *str)
{
    int nb_spaces = 0;

    for (int i = 0; str[i] != '\0'; i++)
        str[i] == ' ' ? nb_spaces++ : 0;
    return nb_spaces;
}

char *formatting_str(char *str)
{
    int wright_malloc = strlen(str) - nb_spaces(str);
    char *new = malloc(sizeof(char) * (wright_malloc));
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            new[a++] = str[i];
        else
            continue;
    }
    new[a] = '\0';
    return new;
}
