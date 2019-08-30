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

    gmax = 5;
    i = 1;
    while (i <= gmax)
    {
        j = 0;
        while (j < (size - ((i - 1) * (size / gmax))))
        {
            if (i % 2)
            {
                
                if (((*stka)->dx > (size * (gmax - i) / gmax)) && ((*stka)->dx <= ((size * (gmax - i + 1)) / gmax)))
                    inst("pb", stka, stkb, (*flgs))
                else
                    inst("ra", stka, stkb, (*flgs));
            }
            else
            {
                if (((*stka)->dx > ((size / gmax) * (i - 1))) && ((*stka)->dx <= ((size / gmax) * i)))
                    inst("pb", stka, stkb, (*flgs))
                inst("rra", stka, stkb, (*flgs));
            }
            j++;
            
        }
        printf("kms\n");
        k = btoa(stka, stkb, flgs, i * (size / gmax)); //i was sorting a seg fault here
        printf("kms\n");
        if (i != gmax)
            while (k--)
                inst(((i % 2) ? "ra" : "rra"), stka, stkb, (*flgs));
        i++;
    }
    k = (gmax / 2) * (size / gmax);
    while (k--)
        inst("rra", stka, stkb, (*flgs));
    return (count);
}