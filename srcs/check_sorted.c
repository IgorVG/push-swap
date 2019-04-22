/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:29:48 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/15 09:29:50 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_opt_rab(t_pack *pk, int elem, char stack)
{
	int dmin_f;
	int dmin_b;

	if (stack == 'b')
	{
		dmin_f = ft_distance_fw(pk->b, elem);
		dmin_b = ft_distance_bk(pk->b, elem);
		if (dmin_f <= dmin_b)
			while (pk->b->d[pk->b->hd] != elem)
				ft_rb(pk->b, pk->o);
		else
			while (pk->b->d[pk->b->hd] != elem)
				ft_rrb(pk->b, pk->o);
	}
	else if (stack == 'a')
	{
		dmin_f = ft_distance_fw(pk->a, elem);
		dmin_b = ft_distance_bk(pk->a, elem);
		if (dmin_f <= dmin_b)
			while (pk->a->d[pk->a->hd] != elem)
				ft_ra(pk->a, pk->o);
		else
			while (pk->a->d[pk->a->hd] != elem)
				ft_rra(pk->a, pk->o);
	}
}

int			ft_check_sorted(t_stack *s, int hd, int rev)
{
	int i;

	i = 0;
	if (rev == 0)
	{
		while (++i < s->ln)
		{
			if (s->d[hd] < s->d[s->next[hd]])
				hd = s->next[hd];
			else
				return (0);
		}
	}
	else if (rev == 1)
	{
		while (++i < s->ln)
		{
			if (s->d[hd] > s->d[s->next[hd]])
				hd = s->next[hd];
			else
				return (0);
		}
	}
	return (1);
}

int			ft_check_sorted_rot(t_stack *s, int rev)
{
	int i;
	int hd;

	i = 0;
	hd = s->hd;
	while (++i <= s->ln)
	{
		if (ft_check_sorted(s, hd, rev))
			return (hd);
		hd = s->next[hd];
	}
	return (0);
}

int			ft_check_sorted_k(t_stack *s, int hd, int k, int rev)
{
	if (rev == 0)
	{
		while (--k)
		{
			if (s->d[hd] < s->d[s->next[hd]])
				hd = s->next[hd];
			else
				return (0);
		}
	}
	else
	{
		while (--k)
		{
			if (s->d[hd] > s->d[s->next[hd]])
				hd = s->next[hd];
			else
				return (0);
		}
	}
	return (1);
}
