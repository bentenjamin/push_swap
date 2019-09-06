/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:10:05 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/06 09:53:25 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
usage: -g5, sets groups to 5\n");
}

char *cint(char *ins, char *stk)
{
    char *s;
    char *ret;

    s = ft_strcat(ins, stk);
    ret = s;
    free(s);
    return (ret);
}

void vstk(t_ps *stka, t_ps *stkb, t_flgs *flgs)
{
    if (flgs->v)
    {
        system("clear");
        ft_putendl("\nStack A\t\tStack B");
        vall(stka, stkb);
        ft_putstr("\n\n");
        usleep(flgs->s);
    }
}

void inst(char *s, t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    caller(s, stka, stkb, flgs);
    ft_putendl(s);
    vstk(*stka, *stkb, *flgs);
}