/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:06:50 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/07 20:53:26 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	main(int argc, char **argv)
{
	t_flgs	*flgs;
	t_ps	*stka;
	t_ps	*stkb;
	char	**s;

	if (argc == 1)
		exit(0);
	s = malloc(1);
	stkb = NULL;
	flgs = (t_flgs *)malloc(sizeof(t_flgs));
	ft_initflgs(&flgs);
	if (!(ft_rd(++argv, &stka, &flgs)))
		erexit();
	vstk(stka, stkb, flgs);
	while ((get_next_line(0, s)) > 0)
	{
		caller(*s, &stka, &stkb, &flgs);
		vstk(stka, stkb, flgs);
	}
	ft_putstr((chkstk(stka, stkb)) ? "OK\n" : "KO\n");
	flgout(flgs);
}
