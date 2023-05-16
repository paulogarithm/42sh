/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** grof_operations_usefull
*/

#include <stdbool.h>
#include <malloc.h>
#include "my/string.h"

#include "grof/operations.h"

char *remove_string(const char *str1, const char *str2)
{
    char *ret = my_newstr(NULL);
    char *tmp = NULL;

    for (size_t n = 0; str1[n] != '\0'; ++n)
        if (my_strcfnd(str2, str1[n]) < 0)
            my_addchar(&ret, str1[n]);
    if (ret[0] != '\"') {
        tmp = my_strcat("\"", ret);
        free(ret);
        ret = my_newstr(tmp);
        free(tmp);
    }
    if (ret[my_strlen(ret) - 1] != '\"')
        my_addchar(&ret, '\"');
    return ret;
}

bool my_atob(const char *str)
{
    if (my_strcmp(str, "true"))
        return true;
    return false;
}

char *my_btoa(const bool b)
{
    char *ret = my_newstr(b ? "true" : "false");
    return ret;
}
