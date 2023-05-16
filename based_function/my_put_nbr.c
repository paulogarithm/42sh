/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** jitter jitter
*/

void my_putchar_max(char c);

int my_put_nbr_max(int nb)
{
    long int nb_cp = (long int)nb;
    long int nb_length = 1;
    long int nb_elem = 0;
    long int nb_index = 0;
    if (nb_cp < 0) {
        my_putchar_max('-');
        nb_cp = nb_cp*(-1);
    }
    if (nb_cp == 0)
        my_putchar_max('0');
    for (long int counter = nb_cp; counter > 0; counter /= 10)
        nb_length *= 10;
    nb_length /= 10;
    for (; nb_length > 0; nb_length /= 10) {
        nb_elem = nb_cp / nb_length;
        nb_index = nb_elem * nb_length;
        my_putchar_max((nb_elem) + '0');
        nb_cp -= nb_index;
    }
    return 0;
}
