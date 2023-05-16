/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strcfnd
*/

#include <stddef.h>
#include <stdbool.h>

size_t my_strlen(const char *str);

long int my_strcfnd(const char *str, const char c)
{
    for (size_t n = 0; str[n] != '\0'; n++)
        if (str[n] == c)
            return (int)n;
    return -1;
}

bool my_strfnd(char *str, const char *find)
{
    size_t find_index = 0;
    size_t find_len = my_strlen(find);

    for (size_t str_index = 0; str[str_index] != '\0'; str_index++) {
        if (str[str_index] == find[find_index])
            find_index += 1;
        else
            find_index = 0;
        if (find_index == find_len)
            return 1;
        str_index += 1;
    }
    return 0;
}
