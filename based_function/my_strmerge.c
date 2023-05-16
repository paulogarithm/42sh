/*
** EPITECH PROJECT, 2023
** my_sstrmerge.c
** File description:
** fusion fo two string
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strcat_max(char *str, char *str_after);
int my_strlen_max(char const *str);
char *my_strcpy_max(char *destination, char const *src);

char *my_strmerge_max(char *str, char *str_after)
{
    int my_len = my_strlen_max(str) + my_strlen_max(str_after) + 1;
    char *new_str = malloc(sizeof(char[my_len]));

    my_strcpy_max(new_str, str);
    my_strcat_max(new_str, str_after);
    new_str[my_len - 1] = '\0';
    return new_str;
}
