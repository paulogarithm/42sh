/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_printf
*/

#include <stdarg.h>
#include <malloc.h>

char *my_newstr(const char *text);
char *my_arrayform(const char **array);
void my_addstr(char **dest, char *add);
void my_addchar(char **dest, char c);
long int my_putstr(char *str);
char *my_itoa(const int num);
char *my_ftoa(const double num);
char *my_ctoa(const char c);

static char *do_switch(const char *str, int *n, va_list ap)
{
    *n += 1;
    switch (str[*n]) {
        case 's':
        return my_newstr(va_arg(ap, char *));
        case 'i':
        case 'd':
        return my_itoa(va_arg(ap, int));
        case 'c':
        return my_ctoa(va_arg(ap, int));
        case 'f':
        return my_ftoa(va_arg(ap, double));
        case 'a':
        return my_arrayform((const char **)va_arg(ap, char **));
        case '%':
        return my_newstr("%");
        default:
        return "";
    }
}

int my_printf(const char *str, ...)
{
    char *final = my_newstr("");
    long int len = 0;
    char *tmp = NULL;
    va_list ap;

    va_start(ap, str);
    for (int n = 0; str[n] != '\0'; n ++) {
        if (str[n] == '%') {
            tmp = do_switch(str, &n, ap);
            tmp = (tmp == NULL) ? my_newstr("null") : tmp;
            my_addstr(&final, tmp);
            free(tmp);
        } else
            my_addchar(&final, str[n]);
    }
    len = my_putstr(final);
    va_end(ap);
    free(final);
    return (int)len;
}
