/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** duplicate a string since the third argument given to the funcction
*/

#include <stdlib.h>

int my_strlen_max(char *str);

char *my_strndup_max(char *str, int number)
{
    char *return_value = malloc(sizeof(char) * (number + 1));

    for (int i = 0; str[i] && i < number; i++) {
        return_value[i] = str[i];
    }
    return_value[number] = '\0';
    return return_value;
}
