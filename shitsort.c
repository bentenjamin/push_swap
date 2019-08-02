#include "ps.h"

int    sptb(t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    int k;

    k = 0;
    while (*stka)
    {
        if (((*stka)->xt) && ((*stka)->num > (*stka)->xt->num))
        {
            caller("sa", stka, stkb);
            ft_putstr_fd("sa\n", 1);
            vstk(*stka, *stkb, (*flgs));
            k++;
        }
        caller("pb", stka, stkb);
        ft_putstr_fd("pb\n", 1);
        vstk(*stka, *stkb, (*flgs));
        k++;
    }
    return (k);
}

int    spta(t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    int k;

    k = 0;
    while (*stkb)
    {
        if (((*stkb)->xt) && ((*stkb)->num < (*stkb)->xt->num))
            {
            caller("sb", stka, stkb);
            ft_putstr_fd("sb\n", 1);
            vstk(*stka, *stkb, (*flgs));
            k++;
        }
        caller("pa", stka, stkb);
        ft_putstr_fd("pa\n", 1);
        vstk(*stka, *stkb, (*flgs));
        k++;
    }
    return (k);
}

int    shitsort(t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    char    i;
    int     k;
    t_ps    *tmp;

    i = 1;
    k = 0;
    while (i)
    {
        k += sptb(stka, stkb, flgs);
        k += spta(stka, stkb, flgs);
        i = 0;
        tmp = *stka;
        while (tmp && i == 0)
        {
            if ((tmp->xt) && (tmp->num > tmp->xt->num))
                i = 1;
            tmp = tmp->xt;
        }
    }
    return (k);
}
