/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:50:28 by bwebb             #+#    #+#             */
/*   Updated: 2019/09/07 21:11:36 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include "../Libft/libft.h"
# Define af (*stka)->dx
# Define as (*stka)->xt->dx
# Define at (*stka)->xt->xt->dx
# Define oddnum (2 - i)
# Define evenum (i + 1)
# Define oddoreven ((gps + ((i % 2 == gps % 2) ? oddnum : evenum)) / 2)
# Define gps (*flgs)->g
# Define rng(temp) (size * (temp) / gps)

typedef struct		s_ps
{
	int				dx;
	int				num;
	struct s_ps		*xt;
}					t_ps;

typedef struct		s_flgs
{
	int				g;
	int				count;
	char			i : 1;
	char			h : 1;
	char			v : 1;
	char			c : 1;
	int				s;
}					t_flgs;

void				caller(char *s, t_ps **stka, t_ps **stkb, t_flgs **flgs);
void				ft_freestck(t_ps **stck);
void				vall(t_ps *ta, t_ps *tb);
void				ft_initflgs(t_flgs **flgs);
void				ft_setflgs(char *s, t_flgs **flgs);
int					ft_stkadd(int num, t_ps **stck);
char				ft_chkdups(int num, t_ps **stk);
int					ft_rd(char **arr, t_ps **stka, t_flgs **flgs);
int					shitsort(t_ps **stka, t_ps **stkb, t_flgs **flgs);
char				chkstk(t_ps *stka, t_ps *stkb);
void				dex(t_ps **stk);
void				printndx(t_ps *stk);
int					stksize(t_ps *stk);
void				startsort(t_ps **sa, t_ps **sb, t_flgs **flgs, int size);
void				inst(char *s, t_ps **stka, t_ps **stkb, t_flgs **flgs);
void				vstk(t_ps *stka, t_ps *stkb, t_flgs *flgs);
void				flgout(t_flgs *flgs);
char				*upordown(t_ps *stk, int indx);
void				defflgs(t_ps **stka, t_flgs **flgs);
void				erexit();

#endif