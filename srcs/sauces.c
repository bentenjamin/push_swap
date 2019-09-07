/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:10:05 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/07 21:32:13 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

char	chkstk(t_ps *stka, t_ps *stkb)
{
	if (stkb)
		return (0);
	while (stka)
	{
		if ((stka->xt) && stka->num > stka->xt->num)
			return (0);
		stka = stka->xt;
	}
	return (1);
}

void	dex(t_ps **stk)
{
	int		i;
	int		j;
	t_ps	*t;
	t_ps	*t1;

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
}

void	printndx(t_ps *stk)
{
	while (stk)
	{
		printf("number: %d. Index: %d\n", stk->num, stk->dx);
		stk = stk->xt;
	}
}

char	*upordown(t_ps *stk, int indx)
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

void	inst(char *s, t_ps **stka, t_ps **stkb, t_flgs **flgs)
{
	caller(s, stka, stkb, flgs);
	ft_putendl(s);
	vstk(*stka, *stkb, *flgs);
}
