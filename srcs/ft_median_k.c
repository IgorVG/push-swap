/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_k.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:44:22 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:44:24 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				cir_f(int hd, int max)
{
	if (hd <= max)
		return (hd);
	return (1);
}

int				cir_b(int hd, int max)
{
	if (hd >= 1)
		return (hd);
	return (max);
}

void			ft_add_delimiter(t_stack *s, int med)
{
	int hd;

	hd = s->hd;
	while (s->d[hd] != med)
		hd = s->next[hd];
	if (s->d[hd] == med)
		s->m[hd] = -1;
}

int				ft_median_k(t_stack *s, int k)
{
	int		med;
	int		d[s->ln];

	ft_stk_to_arr(s, d);
	med = ft_med(d, 0, (s->ln - 1), k);
	return (med);
}

void			ft_position(t_stack *s)
{
	int i;
	int hd;
	int med;

	i = 0;
	hd = s->hd;
	while (++i <= s->ln)
	{
		med = ft_median_k(s, i);
		while (s->d[hd] != med)
			hd = s->next[hd];
		s->p[hd] = i;
	}
}
