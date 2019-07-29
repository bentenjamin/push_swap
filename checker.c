#include "ps.h"

int main(int argc, char **argv)
{
    t_flgs  *flgs;
    t_ps    *stka;
    t_ps    *stkb;
    char    **s;

    if (argc == 1)
        exit(0);
    s = malloc(1);
    stkb = NULL;
    flgs = (t_flgs *)malloc(sizeof(t_flgs));
    if (!(ft_rd(++argv, &stka, &flgs)))
        erexit;
    vstk(stka, stkb, flgs);
    while ((get_next_line(0,s)) > 0)
    {
        caller(*s, &stka, &stkb);
        vstk(stka, stkb, flgs);
    }
    (chkstk(stka, stkb)) ? ft_putstr("OK/n") : ft_putstr("KO/n");
    free(s);
    ft_freestck(&stka);
}