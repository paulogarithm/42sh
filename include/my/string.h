/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_string
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_

    #include <stdbool.h>

void my_addstr(char **a, const char *b);
void my_addchar(char **str, char c);
void my_addcharindex(char **str, char c, const long unsigned index);
void *my_memcpy(void *dest, void *src, unsigned long int size);
void *my_realloc
(void *src, unsigned long int old_size, unsigned long int size);
char *my_newstr(const char *str);
char *my_newnstr(const char *str, unsigned long int n);
void my_strup(char *str);
void my_strlow(char *str);
char *my_strcat(char *restrict dest, const char *restrict src);
char *my_superstrcat(int num, ...);
char *my_strncat
(char *restrict dest, const char *restrict src, unsigned long int len);
void my_strclean(char *str, char c);
bool my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *restrict dest, const char *restrict src);
char *my_strncpy
(char *restrict dest, const char *restrict src, unsigned long int len);
char *my_strcut(const char *str, int beg, int end);
unsigned long int my_strlen(const char *str);
char *my_strnorm(const char *str);
void my_strrev(char *str);
char *my_strjoin(const char **array, const char *join);
char **my_array_str(const char *str);
char **my_strsplit(const char *restrict str, const char *restrict correct);
bool my_strfnd(char *str, const char *find);
long int my_strcfnd(const char *str, const char c);

#endif /* !MY_STRING_H_ */
