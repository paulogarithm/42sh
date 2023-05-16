/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strupper
*/

void my_strup(char *str)
{
    for (int n = 0; str[n] != '\0'; n ++)
        str[n] = str[n] >= 'a' && str[n] <= 'z' ? str[n] - 'a' + 'A' : str[n];
}

void my_strlow(char *str)
{
    for (int n = 0; str[n] != '\0'; n ++)
        str[n] = str[n] >= 'A' && str[n] <= 'Z' ? str[n] - 'A' + 'a' : str[n];
}
