/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:10:05 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/05 17:29:51 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
        usleep(1000000);
    }
}

void inst(char *s, t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    caller(s, stka, stkb, flgs);
    ft_putendl(s);
    vstk(*stka, *stkb, *flgs);
}