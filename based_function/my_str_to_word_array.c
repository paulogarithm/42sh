/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** create a double array
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int nbr_element_for_malloc(char *str, char d)
{
    int total_element = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == d || str[i] == '\0')
            total_element++;
    }
    return total_element + 1;
}

static char *my_strndup_max(char *str, int nbr)
{
    char *return_value = malloc(sizeof(char) * (nbr + 1));

    for (int i = 0; str[i] && i < nbr; i++) {
        return_value[i] = str[i];
    }
    return_value[nbr] = '\0';
    return return_value;
}

static int detecte_the_end_of_a_line(char *str, char d)
{
    int i;

    for (i = 0; str[i] && str[i] != d; i++);
    return i;
}

char **my_str_to_word_array_strtok_max(char *str, char d)
{
    char separator[] = {d, '\0'};
    char **array = NULL;
    int nbr_sep = nbr_element_for_malloc(str, d);

    array = malloc(sizeof(char *[nbr_sep + 1]));
    if (array == NULL)
        return NULL;
    array[0] = strtok(str, separator);
    for (int i = 1; i < (nbr_sep); i += 1) {
        array[i] = strtok(NULL, separator);
    }
    array[nbr_sep] = NULL;
    return array;
}

char **my_str_to_word_array_max(char *str, char d)
{
    int cmptr1 = 0;
    int cmptr2 = 0;
    int size_word = 0;
    int nbr_elemnt = nbr_element_for_malloc(str, d);

    char **array = malloc(sizeof(char *) * (nbr_elemnt + 1));
    while (cmptr2 < nbr_elemnt) {
        size_word = detecte_the_end_of_a_line(str + cmptr1, d);
        array[cmptr2] = my_strndup_max(str + cmptr1, size_word);
        cmptr1 += size_word + 1;
        cmptr2++;
    }
    array[cmptr2] = NULL;
    return array;
}
