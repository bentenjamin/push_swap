#include "ps.h"

int main(int argc, char **argv)
{
    t_flgs  *flgs;
    t_ps    *stka;
    t_ps    *stkb;

    if (argc == 1)
        erexit;
    stkb = NULL;
    flgs = (t_flgs *)malloc(sizeof(t_flgs));
    if (!(ft_rd(++argv, &stka, &flgs)))
        erexit;
    vstk(stka, stkb, flgs);
    ft_putnbr(sortstk(&stka, &stkb, &flgs));
    ft_putstr(" operations");
    ft_freestck(&stka);
}