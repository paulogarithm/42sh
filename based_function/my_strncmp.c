/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** compare a string with the number of charcatère to watch
*/

int my_strncmp_max(char const *str_nbr1, char const *str_nbr2, int n)
{
    int i = 0;
    for (; str_nbr1[i]
    && str_nbr2[i]
    && str_nbr1[i] == str_nbr2[i]
    && i < n; i += 1) {
    }
    return (str_nbr1[i] - str_nbr2[i]);
}
