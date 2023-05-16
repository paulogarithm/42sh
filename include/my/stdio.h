/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_stdio
*/

#ifndef MY_STDIO_H_
    #define MY_STDIO_H_

    #include <stdbool.h>

    #define SRL_CREATE 1
    #define SRL_OVRWRT 2
    #define SRL_APPEND 4

char my_getchar(void);
char *my_scanf(const char *to_show);
int my_printf(const char *str, ...);
char *my_parsing(const char *path);
char **my_array_parsing(const char *path);
bool my_serial(const char *file, const char *line, const char flags);
void my_putchar(char c);
long int my_putstr(const char *str);
long int my_putstrd(int fd, const char *str);


#endif /* !MY_STDIO_H_ */
