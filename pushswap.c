/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:38:23 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/06 09:35:28 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int main(int argc, char **argv)
{
    t_flgs  *flgs;
    t_ps    *stka;
    t_ps    *stkb;
    int     i;
    
    if (argc == 1)
        erexit;
    stkb = NULL;
    flgs = (t_flgs *)malloc(sizeof(t_flgs));
    ft_initflgs(&flgs);
    if (!(ft_rd(++argv, &stka, &flgs)))
        erexit;
    i = dex(&stka);
    vstk(stka, stkb, flgs);
    startsort(&stka, &stkb, &flgs, stksize(stka));
    flgout(flgs);
    ft_freestck(&stka);
}