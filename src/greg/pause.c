/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** pause when you hit Ctrl-Z
*/

#include "structure.h"
#include "my/stdio.h"

int compteur_sig(int nb)
{
    static int nbr = 0;

    if (nb == 2)
        return nbr;
    if (nb == 1)
        nbr += nb;
    else
        nbr = 0;
    return nbr;
}

int pause(void)
{
    compteur_sig(-1);
    my_printf("pipi\n");
    return 0;
}

void is_pause(int sig)
{
    sig = 1;
    compteur_sig(sig);
    return;
}
