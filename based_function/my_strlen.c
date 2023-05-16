/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** jitter jitter
*/

int my_strlen_max(char const *str)
{
    int i = 0;
    int cmptr = 0;
    for (; str[i] != '\0'; i++) {
        cmptr++;
    }
    return cmptr;
}
