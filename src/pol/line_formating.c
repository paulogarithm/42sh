/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** line_formating
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

#include "structure.h"
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

char *get_show(const int is_empty, minish_t *minish)
{
    char *ret = NULL;
    char *tmp = NULL;
    char *path = getcwd(NULL, 0);
    char *homepath = get_envval((const char **)minish->env, "HOME");

    if (is_empty || path == NULL) {
        ret = my_newstr("> ");
        return ret;
    }
    tmp = get_lastword(path, "/");
    if (my_strcmp(path, homepath)) {
        free(tmp);
        tmp = my_newstr("~");
    }
    ret = my_superstrcat(3, "\033[1;34m>  \033[1;95m", tmp, "\033[m ");
    free(tmp);
    free(path);
    free(homepath);
    return ret;
}

char *get_absolutepath(const char *str)
{
    char **split = my_strsplit(str, "/");
    int len = my_arraylen((const char **)split);
    char *ret = NULL;
    char *tmp = NULL;

    if (split == NULL || len < 1)
        return NULL;
    my_arraypop(&split, len);
    tmp = my_strjoin((const char **)split, "/");
    ret = realpath(tmp, NULL);
    free(tmp);
    my_arrayfree(split);
    return ret;
}

int replace_vaguelette(char ***array, const char **env)
{
    char *homevar = NULL;
    char *res = NULL;
    char *cut = NULL;

    for (int n = 1; (*array)[n] != NULL; n++) {
        if ((*array)[n][0] != '~')
            continue;
        if (homevar == NULL)
            homevar = get_envval(env, "HOME");
        if (homevar == NULL)
            return my_printf("No $home variable set.\n");
        res = my_newstr(homevar);
        cut = my_strcut((*array)[n], 1, my_strlen((*array)[n]));
        my_addstr(&res, cut);
        free((*array)[n]);
        (*array)[n] = res;
        free(cut);
    }
    free(homevar);
    return 0;
}

static char **get_allfiles_loop(const char *src, DIR *dir, bool onlyfolder)
{
    char **array = my_newarray(NULL);
    char *realname = my_newstr(NULL);
    struct dirent *file = NULL;
    struct stat st;

    while (1) {
        file = readdir(dir);
        if (file == NULL)
            break;
        free(realname);
        realname = my_superstrcat(2, src, file->d_name);
        if (stat(realname, &st) < 0 || (onlyfolder && !S_ISDIR(st.st_mode))
        || my_strcmp(".", file->d_name) || my_strcmp("..", file->d_name))
            continue;
        my_arrayadd(&array, file->d_name);
    }
    free(realname);
    return array;
}

char **get_allfiles(const char *src, bool onlyfolder)
{
    DIR *dir = NULL;
    char **array = NULL;

    dir = opendir(src);
    if (dir == NULL)
        return NULL;
    array = get_allfiles_loop(src, dir, onlyfolder);
    closedir(dir);
    return array;
}
