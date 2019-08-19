#include "ps.h"

void    splat(t_ps **stka, t_ps **stkb, t_flgs **flgs, int ndx)
{
    int i;

    i = 0;
    while (i < 2 * ndx)
    {
        if ((*stka)->dx <= ndx)
        {
            caller("pb", stka, stkb);
            ft_putstr("pb");
            vstk((*stka), stkb, flgs);
        }
    }
}

int qsort(t_ps **stka, t_ps **stkb, t_flgs **flgs, int size)
{
    int gp;

    gp = 1;

}