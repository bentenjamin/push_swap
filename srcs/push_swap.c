/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:38:23 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/07 22:42:17 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	main(int argc, char **argv)
{
	t_flgs	*flgs;
	t_ps	*stka;
	t_ps	*stkb;

	if (argc == 1)
		erexit();
	stkb = NULL;
	flgs = (t_flgs *)malloc(sizeof(t_flgs));
	ft_initflgs(&flgs);
	if (!(ft_rd(++argv, &stka, &flgs)))
		erexit();
	defflgs(&stka, &flgs);
	dex(&stka);
	startsort(&stka, &stkb, &flgs, stksize(stka));
	flgout(flgs);
}
