/*
** EPITECH PROJECT, 2023
** my_strcpi.c
** File description:
** my_strcpi
*/

char *my_strcpy_max(char *destination, char const *src)
{
    int cmptr = 0;
    for (; src[cmptr] != '\0'; cmptr++) {
        destination[cmptr] = src[cmptr];
    }
    destination[cmptr] = '\0';
    return destination;
}
