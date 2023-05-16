/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_getchar
*/

#include <unistd.h>
#include <malloc.h>

char *my_newstr(const char *str);
void my_addchar(char **str, char c);

char my_getchar(void)
{
    char ret = 0;
    char *str = my_newstr(NULL);
    char *tmp = NULL;
    ssize_t readres = 0;

    while (1) {
        tmp = my_newstr("?");
        readres = read(STDIN_FILENO, tmp, sizeof(char));
        if (readres < 0 || tmp[0] == '\n')
            break;
        my_addchar(&str, tmp[0]);
        free(tmp);
    }
    ret = str[0];
    free(tmp);
    free(str);
    return ret;
}
