/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pins.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:12:00 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/06 16:13:36 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void    swp(t_ps **stk)
{
    t_ps *t;

    if (!(*stk) || !((*stk)->xt))
        return ;
    t = (*stk)->xt;
    (*stk)->xt = (*stk)->xt->xt;
    t->xt = (*stk);
    *stk = t;
}

void    psh(t_ps **stkfrm, t_ps **stkto)
{
    t_ps *tmp;

    if (!(*stkfrm))
        return ;
    tmp = *stkto;
    *stkto = *stkfrm;
    *stkfrm = (*stkfrm)->xt;
    (*stkto)->xt = tmp;
}

void    rot(t_ps **stk)
{
    t_ps    *tmp;

    if (!(*stk) || !((*stk)->xt))
        return ;
    tmp = *stk;
    while (tmp->xt)
        tmp = tmp->xt;
    tmp->xt = *stk;
    *stk = (*stk)->xt;
    tmp->xt->xt = NULL;
}

void    revrot(t_ps **stk)
{
    t_ps    *tmp;

    if (!(*stk) || !((*stk)->xt))
        return ;
    tmp = *stk;
    while (tmp->xt->xt)
        tmp = tmp->xt;
    tmp->xt->xt = *stk;
    *stk = tmp->xt;
    tmp->xt = NULL;
}

void    caller(char *s, t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
    if (ft_strequ(s,"sa") || ft_strequ(s,"ss"))
        swp(stka);
    if (ft_strequ(s,"sb") || ft_strequ(s,"ss"))
        swp(stkb);
    if (ft_strequ(s,"pa"))
        psh(stkb, stka);
    if (ft_strequ(s,"pb"))
        psh(stka, stkb);
    if (ft_strequ(s,"ra") || ft_strequ(s,"rr"))
        rot(stka);
    if (ft_strequ(s,"rb") || ft_strequ(s,"rr"))
        rot(stkb);
    if (ft_strequ(s,"rra") || ft_strequ(s,"rrr"))
        revrot(stka);
    if (ft_strequ(s,"rrb") || ft_strequ(s,"rrr"))
        revrot(stkb);
    (*flgs)->count++;
}