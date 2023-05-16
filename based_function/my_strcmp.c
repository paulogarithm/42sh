/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** compare two string
*/

int my_strcmp_max(char const *str_nbr1, char const *str_nbr2)
{
    int i = 0;
    for (; str_nbr1[i] && str_nbr2[i] && str_nbr1[i] == str_nbr2[i]; i++);
    return (str_nbr1[i] - str_nbr2[i]);
}
