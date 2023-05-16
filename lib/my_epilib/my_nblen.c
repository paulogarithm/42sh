/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_nblen
*/

int my_abs(int a);
int my_pow(int a, unsigned int b);

int my_nblen(int nb)
{
    int ret;

    nb = my_abs(nb);
    for (ret = 0; ret < 1000000; ret ++)
        if (nb - my_pow(10, ret) < 0)
            return ret;
    return 0;
}
