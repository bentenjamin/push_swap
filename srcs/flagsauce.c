/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsauce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:35:39 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/06 16:15:50 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void    ft_initflgs(t_flgs **flgs)
{
    (*flgs)->count = 0;
    (*flgs)->s = 100000;
    (*flgs)->i = 0;
    (*flgs)->h = 0;
    (*flgs)->g = 0;
    (*flgs)->c = 0;
    (*flgs)->v = 0;
}

void    ft_setflgs(char *s, t_flgs **flgs)
{
    int i;

    i = 0;
    while (s[++i])
        if (s[i] == 'c')
            (*flgs)->c = 1;
        else if (s[i] == 'v')
            (*flgs)->v = 1;
        else if (s[i] == 'i')
            (*flgs)->i = 1;
        else if (s[i] == 'h')
            (*flgs)->h = 1;
        else if (s[i] == 'g')
        {
            (*flgs)->g = atoi(s + ++i);
            while (isdigit(s[i]))
                i++;
        }
        else if (s[i] == 's')
        {
            (*flgs)->s = atoi(s + ++i);
            while (isdigit(s[i]))
                i++;
        }
}

int closestmult(int size, int start)
{
    int i;

    i = 1;
    while (start - i != 1)
    {
        if (size % (start - i) == 0)
            return (start - i);
        if (size % (start + i) == 0)
            return (start + i);
        i++;
    }
    return (1);
}

void defflgs(t_ps **stka, t_flgs **flgs)
{
    if (!((*flgs)->g))
        (*flgs)->g = 5 + (5 * ((ft_rndwncbrt(stksize(*stka)) / 5)));
    if (stksize(*stka) % gps)
        gps = closestmult(stksize(*stka), gps);
}

void flgout(t_flgs *flgs)
{
    if (flgs->i)
    {
        ft_putnbr(flgs->count);
        ft_putstr(" operations\n");
    }
    if (flgs->h)
        ft_putstr("flags:\n\
    -i : print number of operations\n\
    -h : help\n\
    -c : colours\n\
    -v : visualise the sort\n\
    -s : speed of the visualiser. default is 100000\n\
    -g : specify the amount of groups to split into while sorting. \
Will be forced to closest multiple of list size if it isnt already. \
usage: -g5, sets groups to 5\n");
}