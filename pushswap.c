#include "ps.h"

int main(int argc, char **argv)
{
    t_flgs  *flgs;
    t_ps    *stka;
    t_ps    *stkb;
    int     i;
    
    if (argc == 1)
        erexit;
    stkb = NULL;
    flgs = (t_flgs *)malloc(sizeof(t_flgs));
    if (!(ft_rd(++argv, &stka, &flgs)))
        erexit;
    i = dex(&stka);
    vstk(stka, stkb, flgs);
    ft_putnbr(gsort(&stka, &stkb, &flgs, stksize(stka)));
    ft_putstr(" operations\n");
    ft_freestck(&stka);
}