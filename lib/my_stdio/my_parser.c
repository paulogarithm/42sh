/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_freed
*/

#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/stat.h>

ssize_t *my_putstrd(int descriptor, const char *message);
char **my_strsplit(const char *restrict str, const char *restrict correct);

char *my_parsing(const char *path)
{
    int fd = -1;
    ssize_t res = -1;
    struct stat st;
    char *buf = NULL;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return NULL;
    res = stat(path, &st);
    if (res < 0)
        return NULL;
    buf = malloc(sizeof(char) * (st.st_size + 1));
    if (buf == NULL)
        return NULL;
    res = read(fd, buf, st.st_size);
    if (res < 0)
        return NULL;
    buf[st.st_size] = '\0';
    return buf;
}

char **my_array_parsing(const char *path)
{
    char *str = my_parsing(path);
    char **array = NULL;

    if (str == NULL)
        return NULL;
    array = my_strsplit(str, "\n");
    free(str);
    return array;
}
