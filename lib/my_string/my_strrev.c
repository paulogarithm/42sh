/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_revstr
*/

#include <stddef.h>

size_t my_strlen(const char *str);

void my_strrev(char *str)
{
    size_t len = my_strlen((const char *)str);
    size_t j = len - 1;
    char tmp = '\0';

    for (size_t i = 0; i < ((len + 1) / 2); i ++) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j -= 1;
    }
}
