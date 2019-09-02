#include "ps.h"

char    *upordown(t_ps *stk, int indx)
{
    int i;
    int size;

    i = 1;
    size = stksize(stk);
    while (stk->dx != indx)
    {
        i++;
        stk = stk->xt;
    }
    if ((size - (i - 1)) < i)
        return ("rrb");
    return ("rb");
}

int btoa(t_ps **stka, t_ps **stkb, t_flgs **flgs, int mxdx)
{
    int size;
    char *dir;

    size = stksize(*stkb);
    while (*stkb)
    {
        dir = upordown((*stkb), mxdx);
        while ((*stkb)->dx != mxdx)
            inst(dir, stka, stkb, (*flgs));
        inst("pa", stka, stkb, (*flgs));
        mxdx--;
    }
    return (size);
}

int gsort(t_ps **stka, t_ps **stkb, t_flgs **flgs, int size)
{
    int i;
    int j;
    int k;
    int gmax;

    gmax = 10;
    i = 1;
    while (i <= gmax)
    {
        j = 0;
        while (j < (size - ((i - 1) * (size / gmax))))
        {
            if (i % 2)
            {
                
                if (((*stka)->dx > (size * (gmax - ((i + 1) / 2)) / gmax)) && ((*stka)->dx <= ((size * (gmax - ((i + 1) / 2) + 1)) / gmax)))
                    inst("pb", stka, stkb, (*flgs))
                else
                    inst("ra", stka, stkb, (*flgs));
            }
            else
            {
                inst("rra", stka, stkb, (*flgs));
                if (((*stka)->dx > ((size * ((i / 2) - 1)) / gmax)) && ((*stka)->dx <= ((size * (i / 2)) / gmax)))
                    inst("pb", stka, stkb, (*flgs))
            }
            j++;
            
        }
        k = btoa(stka, stkb, flgs, (i % 2) ? (size * (gmax - ((i + 1) / 2) + 1)) / gmax : size * (i / 2) / gmax);
        if (i != gmax && !(i % 2))
            while (k--)
                inst("ra", stka, stkb, (*flgs));
        i++;
    }
    k = ((gmax / 2) - ((i % 2) ? 1 : 0)) * (size / gmax);
    while (k--)
        inst("rra", stka, stkb, (*flgs));
    return (count);
}