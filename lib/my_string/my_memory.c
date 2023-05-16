/*
** EPITECH PROJECT, 2023
** rpg-bg
** File description:
** allocs
*/

#include <stdlib.h>

void *my_memcpy(void *dest, void *src, size_t size)
{
    char *n_dest = dest;
    char *n_src = src;

    while (size--)
        *n_dest++ = *n_src++;
    return dest;
}

void *my_realloc(void *src, size_t old_size, size_t size)
{
    void *new = malloc(size);

    if (new == NULL)
        return NULL;
    new = my_memcpy(new, src, old_size);
    free(src);
    return new;
}
