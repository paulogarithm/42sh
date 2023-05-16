/*
** EPITECH PROJECT, 2023
** lib2
** File description:
** my_itoa
*/

int my_abs(const int n);
char *my_newstr(const char *str);
void my_addchar(char **str, char c);
void my_strrev(char *str);

char *my_itoa(const int nb)
{
    char *ret = my_newstr("");
    int tmp_nb = 0;
    int nnb = my_abs(nb);

    for (int i = 0; nnb >= 10; i ++) {
        tmp_nb = (nnb % 10);
        nnb = (nnb - tmp_nb) / 10;
        my_addchar(&ret, tmp_nb + '0');
    }
    my_addchar(&ret, nnb + '0');
    if (nb < 0)
        my_addchar(&ret, '-');
    my_strrev(ret);
    return ret;
}
