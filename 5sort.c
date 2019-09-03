/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:23:56 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/03 13:02:57 by bwebb            ###   ########.fr       */
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

    i = 1;
    while (i <= (*flgs)->g)
    {
        j = 0;
        while (j < (size - ((i - 1) * (size / (*flgs)->g))))
        {
            if (i % 2)
            {
                
                if (((*stka)->dx > (size * ((((*flgs)->g - i + 2) / 2) - 1) / (*flgs)->g)) && ((*stka)->dx <= ((size * ((((*flgs)->g - i + 2) / 2)) / (*flgs)->g))))
                    inst("pb", stka, stkb, (*flgs))
                else
                    inst("ra", stka, stkb, (*flgs));
            }
            else
            {
                inst("rra", stka, stkb, (*flgs));
                if (((*stka)->dx > ((size * ((((*flgs)->g + i + 1) / 2) - 1)) / (*flgs)->g)) && ((*stka)->dx <= ((size * (((*flgs)->g + i + 1) / 2)) / (*flgs)->g)))
                    inst("pb", stka, stkb, (*flgs))
            }
            j++;
            
        }
        k = btoa(stka, stkb, flgs, (i % 2) ? (size * (((*flgs)->g - i + 2) / 2)) / (*flgs)->g : size * (((*flgs)->g + i + 1) / 2) / (*flgs)->g);
        if (i != (*flgs)->g && !(i % 2))
            while (k--)
                inst("ra", stka, stkb, (*flgs));
        i++;
    }
    return (count);
}