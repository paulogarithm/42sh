/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_stdarray
*/

#ifndef MY_STDARRAY_H_
    #define MY_STDARRAY_H_

void my_arrayadd(char ***array, const char *str);
void my_arraypop(char ***array, const unsigned long pos);
void my_arraysuperpop
(char ***array, const unsigned long p, const unsigned long s);
long int my_arrayindex(const char **array, const char *str);
char **my_arraycat(char **a, char **b);
void my_arrayfree(char **array);
char *my_arrayform(const char **array);
unsigned long my_arraydisp(const char **array);
unsigned long my_arraylen(const char **array);
char **my_newarray(const char **array);

#endif /* !MY_STDARRAY_H_ */
