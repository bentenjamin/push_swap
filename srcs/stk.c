/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:39:54 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/07 21:32:21 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	ft_freestck(t_ps **stck)
{
	if (*stck)
	{
		if ((*stck)->xt != NULL)
			ft_freestck(&((*stck)->xt));
		free(*stck);
	}
}

int		ft_stkadd(int num, t_ps **stck)
{
	t_ps	*nd;
	t_ps	*prevnode;

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

char	ft_chkdups(int num, t_ps **stk)
{
	if (*stk)
	{
		if (num == (*stk)->num)
			return (1);
		if (!((*stk)->xt))
			return (0);
		return (ft_chkdups(num, &((*stk)->xt)));
	}
	return (0);
}

int		ft_rd(char **arr, t_ps **stka, t_flgs **flgs)
{
	int		i;
	int		k;
	char	**splt;

	i = -1;
	while (arr[++i])
		if (ft_strchr(arr[i], ' '))
		{
			k = 0;
			splt = ft_strsplit(arr[i], ' ');
			ft_rd(splt, stka, flgs);
		}
		else if (arr[i][0] == '-')
			ft_setflgs(arr[i], flgs);
		else if ((!(ft_isonly(arr[i], ft_isdigit))) || \
				(ft_atol(arr[i]) > INT32_MAX) || \
				ft_chkdups(ft_atoi(arr[i]), stka) || \
				(!(ft_stkadd(ft_atoi(arr[i]), stka))))
			return (0);
	defflgs(stka, flgs);
	return (1);
}

int		stksize(t_ps *stk)
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
