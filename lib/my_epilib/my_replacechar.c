/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_replacechar
*/

void my_replacechar(char *str, char obj, char rep)
{
    for (int n = 0; str[n] != '\0'; n ++)
        if (str[n] == obj)
            str[n] = rep;
}
