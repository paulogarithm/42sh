/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** duplicate a string in to an other
*/

#include <stdlib.h>

int my_strlen_max(char *str);

char *my_strdup_max(char *str)
{
    int nbr = my_strlen_max(str);
    char *return_value = malloc(sizeof(char) * (nbr + 1));

    for (int i = 0; str[i] && i < nbr; i++) {
        return_value[i] = str[i];
    }
    return_value[nbr] = '\0';
    return return_value;
}
