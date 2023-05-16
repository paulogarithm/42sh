/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "structure.h"

Test(based_function, my_putchar) {
    cr_assert_eq(my_putchar_max('c'), 0);
}

Test(based_function, my_putstr) {
     cr_assert_eq(my_putstr_max("42sh"), 0);
}

Test(based_function, my_strcmp) {
    cr_assert_eq(my_strcmp_max("42sh", "42sh"), 0);
}

Test(based_function, my_strcmp_2) {
    cr_assert_eq(my_strcmp_max("42ssh", "42sth"), -1);
}

Test(based_function, my_strdup) {
    cr_assert_str_eq(my_strdup_max("42sh"), "42sh");
}

Test(based_function, my_strmerge) {
    char *res = "42sh42sh";
    cr_assert_str_eq(my_strmerge_max("42sh", "42sh"), res);
}

Test(based_function, my_strndup) {
    cr_assert_str_eq(my_strndup_max("42shmax", 4), "42sh");
}

Test(based_function, my_putnbr_1) {
     cr_assert_eq(my_put_nbr_max(42), 0);
}

Test(based_function, my_putnbr_2) {
     cr_assert_eq(my_put_nbr_max(-42), 0);
}

Test(based_function, my_putnbr_3) {
     cr_assert_eq(my_put_nbr_max(0), 0);
}

Test(based_function, my_strcat) {
    char *dest = malloc(sizeof(char) * 5);
    dest[0] = '4';
    dest[1] = '2';
    dest[2] = '\0';
    cr_assert_str_eq(my_strcat_max(dest, "sh"), "42sh");
}

Test(based_function, my_strcpy) {
    char *dest = malloc(sizeof(char) * 5);
    cr_assert_str_eq(my_strcpy_max(dest, "42sh"), "42sh");
}

Test(based_function, my_strlen) {
    cr_assert_eq(my_strlen_max("42sh"), 4);
}

Test(based_function, my_strncmp) {
    cr_assert_eq(my_strncmp_max("42sh", "42sh", 2), 0);
}

Test(based_function, my_strncmp_2) {
    cr_assert_eq(my_strncmp_max("42ssh", "42sth", 3), -1);
}

Test(based_function, my_strncmp_3) {
    cr_assert_eq(my_strncmp_max("4567", "1234", 4), 3);
}
