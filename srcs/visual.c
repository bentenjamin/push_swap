/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:43:41 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/06 17:12:37 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void    erexit()
{
    ft_putstr_fd("Error\n", 1);
    exit(1);
}

void    vall(t_ps *ta, t_ps *tb)
{
    (ta) ? ft_putnbr(ta->num) : ft_putchar('-');
    ft_putchar('\t');
    if (!ta || (ta->num < 10000000))
        ft_putchar('\t');
    (tb) ? ft_putnbr(tb->num) : ft_putchar('-');
    ft_putchar('\n');
    ta = (ta && ta->xt) ? ta->xt : NULL;
    tb = (tb && tb->xt) ? tb->xt : NULL;
    if (ta || tb)
        vall(ta, tb);
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