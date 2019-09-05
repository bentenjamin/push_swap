/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:23:56 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/05 17:33:51 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        return ("rr");
    return ("r");
}

int btoa(t_ps **stka, t_ps **stkb, t_flgs **flgs, int mxdx)
{
    int size;

    size = stksize(*stkb);
    while (*stkb)
    {
        while ((*stkb)->dx != mxdx)
            inst(cint(upordown((*stkb), mxdx), "b"), stka, stkb, flgs);
        inst("pa", stka, stkb, flgs);
        mxdx--;
    }
    return (size);
}

void sorthree(t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    if ((af < as && af < at && as > at) || \
        (af > as && af < at && as < at) || \
        (af > as && af > at && as > at))
            inst("sa", stka, stkb, flgs);
    if (af < as && af > at && as > at)
        inst("rra", stka, stkb, flgs);
    if (af > as && af > at && as < at)
        inst("ra", stka, stkb, flgs);    
}

void sortfive(t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    int j;
    int i;
    
    j = 0;
    i = 0;
    while (++j < 6 && i < 2)
        if (af == 1 || af == 2)
        {
            i++;
            inst("pb", stka, stkb, flgs);
        }
        else
            inst("ra", stka, stkb, flgs);
    if ((*stkb)->dx < (*stkb)->xt->dx)
       inst("sb", stka, stkb, flgs); 
    sorthree(stka, stkb, flgs);
    inst("pa", stka, stkb, flgs);
    inst("pa", stka, stkb, flgs);
}

void    gsort(t_ps **stka, t_ps **stkb, t_flgs **flgs, int size)
{
    int i;
    int j;
    int k;

    i = 1;
    while (i <= (*flgs)->g)
    {
        j = -1;
        while (++j < (size - ((i - 1) * (size / (*flgs)->g))))
            if (!(i % 2))
                inst("rra", stka, stkb, flgs);
            if ((af > (size * ((((*flgs)->g + (i % 2) ? 2 - i : i + 1) / 2) - 1) / (*flgs)->g)) && (af <= ((size * ((((*flgs)->g + (i % 2) ? 2 - i : i + 1) / 2)) / (*flgs)->g))))
                inst("pb", stka, stkb, flgs);
            else if (i % 2)
                inst("ra", stka, stkb, flgs);
        k = btoa(stka, stkb, flgs, (i % 2) ? (size * (((*flgs)->g - i + 2) / 2)) / (*flgs)->g : size * (((*flgs)->g + i + 1) / 2) / (*flgs)->g);
        if (i != (*flgs)->g && !(i % 2))
            while (k--)
                inst("ra", stka, stkb, flgs);
        i++;
    }
}

void    startsort(t_ps **stka, t_ps **stkb, t_flgs **flgs, int size)
{
    if (chkstk(*stka, *stkb))
        return ;
    if (size == 3)
        sorthree(stka, stkb, flgs);
    else if (size == 5)
        sortfive(stka, stkb, flgs);
    else
        gsort(stka, stkb, flgs, size);
}