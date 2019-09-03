/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:39:54 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/03 15:48:26 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    ft_freestck(t_ps **stck)
{
    if (*stck)
    {
        if ((*stck)->xt != NULL)
            ft_freestck(&((*stck)->xt));
        free(*stck);
    }
}

void    vall(t_ps *ta, t_ps *tb)
{
    (ta) ? ft_putnbr(ta->num) : ft_putchar('-');
    ft_putchar('\t');
    if (!ta || (ta->num < 10000000))
        ft_putchar('\t');
    (tb) ? ft_putnbr(tb->num) : ft_putchar('-');
    ft_putchar('\n');
    ta = (ta) ? ((ta->xt) ? ta->xt : NULL) : NULL;
    tb = (tb) ? ((tb->xt) ? tb->xt : NULL) : NULL;
    if (ta || tb)
        vall(ta, tb);
}

void    ft_initflgs(t_flgs **flgs)
{
    (*flgs)->g = 0;
    (*flgs)->c = 0;
    (*flgs)->v = 0;
}

int    ft_setflgs(char *s, t_flgs **flgs, int gps)
{
    int i;

    i = 0;
    while (s[++i])
        if (s[i] == 'c')
            (*flgs)->c = 1;
        else if (s[i] == 'v')
            (*flgs)->v = 1;
        else if (s[i] == 'g')
            (*flgs)->g = gps;
    return ((s[i] == 'g') ? 1 : 0);
}

int ft_stkadd(int num, t_ps **stck)
{
    t_ps    *nd;
    t_ps    *prevnode;

    nd = *stck;
    prevnode = NULL;
    while (nd)
    {
        prevnode = nd;
        nd = nd->xt;
    }
    if (!(nd = (t_ps *)malloc(sizeof(t_ps))))
        return (0);
    nd->num = num;
    nd->xt = NULL;
    nd->dx = 0;
    if (!*stck)
        *stck = nd;
    if (prevnode)
        prevnode->xt = nd;
    return (1);
}

char    ft_chkdups(int num, t_ps **stk)
{
    if (*stk)
    {
        if (num == (*stk)->num)
            return (1);
        if (!((*stk)->xt))
            return (0);
        return(ft_chkdups(num, &((*stk)->xt)));
    }
    return (0);
}

int ft_rd(char **arr, t_ps **stka, t_flgs **flgs)
{
    int     i;
    int     k;
    char    **splt;

    i = -1;
    while (arr[++i])
        if (ft_strchr(arr[i], ' '))
        {
            k = 0;
            splt = ft_strsplit(arr[i], ' ');
            ft_rd(splt, stka, flgs);
        }
        else if (arr[i][0] == '-')
            i += ft_setflgs(arr[i], flgs, ft_atoi(arr[i + 1]));
        else if ((!(ft_isonly(arr[i], ft_isdigit))) || \
                (ft_atol(arr[i]) > INT32_MAX) || \
                ft_chkdups(ft_atoi(arr[i]), stka) || \
                (!(ft_stkadd(ft_atoi(arr[i]), stka))))
            return (0);
    if (!((*flgs)->g))
        (*flgs)->g = 5 + (5 * ((ft_rndwncbrt(stksize(*stka)) / 5)));
    return (1);
}

char    chkstk(t_ps *stka, t_ps *stkb)
{
    if (stkb)
        return (0);

    while (stka)
    {
        if (stka->num > stka->xt->num)
            return (0);
        stka = stka->xt;
    }
    return (1);
}

int stksize(t_ps *stk)
{
    int i;

    i = 0;
    while (stk)
    {
        i++;
        stk = stk->xt;
    }
    return (i);
}

int    dex(t_ps **stk)
{
    int i;
    int j;
    t_ps *t;
    t_ps *t1;

    i = 0;
    t = (*stk);
    j = stksize(*stk);
    while (i < j)
    {
        t1 = (*stk);
        t = t1;
        while (t->dx)
            t = t->xt;
        while (t1)
        {
            if ((t1->num < t->num) && !(t1->dx))
                t = t1;
            t1 = t1->xt;
        }
        if (!(t->dx))
            t->dx = ++i;
    }
    return (i);
}

void printndx(t_ps *stk)
{
    while (stk)
    {
        printf("number: %d. Index: %d\n", stk->num, stk->dx);
        stk = stk->xt;
    }
}