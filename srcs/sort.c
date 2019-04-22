/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:30:00 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/15 09:30:02 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_less_med_pb(t_pack *pk)
{
	int i;
	int med;

	med = pk->a->ln / 2 + pk->a->ln % 2;
	i = med;
	med = ft_median_k(pk->a, med);
	while (i)
	{
		if (pk->a->d[pk->a->hd] <= med)
		{
			ft_pb(pk->a, pk->b, pk->o);
			i--;
		}
		else
			ft_ra(pk->a, pk->o);
	}
}

static int		ft_more_med_pa_less(t_pack *pk, int med, int i)
{
	med = pk->b->ln / 2;
	i = med;
	med = ft_median_k(pk->b, med);
	while (i)
	{
		if (pk->b->d[pk->b->hd] <= med)
		{
			ft_pa(pk->a, pk->b, pk->o);
			i--;
		}
		else
			ft_rb(pk->b, pk->o);
		if (pk->a->p[pk->a->hd] == pk->a->p[pk->a->prev[pk->a->hd]] + 1)
			ft_ra(pk->a, pk->o);
	}
	return (0);
}

static void		ft_more_med_pa_partition(t_pack *pk, int med, int i)
{
	while (i)
	{
		if (pk->b->d[pk->b->hd] > med)
		{
			ft_pa(pk->a, pk->b, pk->o);
			i--;
		}
		else if (pk->b->p[pk->b->hd] == pk->a->p[pk->a->prev[pk->a->hd]] + 1)
		{
			ft_pa(pk->a, pk->b, pk->o);
			ft_ra(pk->a, pk->o);
		}
		else
			ft_rb(pk->b, pk->o);
	}
}

int				ft_more_med_pa(t_pack *pk)
{
	int med;
	int i;

	med = 0;
	i = 0;
	if (pk->b->ln < 4)
		return (0);
	if (pk->b->ln <= 6 && pk->b->ln)
		return (ft_more_med_pa_less(pk, med, i));
	med = pk->b->ln / 2 + pk->b->ln % 2;
	i = pk->b->ln - med;
	med = ft_median_k(pk->b, med);
	ft_more_med_pa_partition(pk, med, i);
	pk->a->m[pk->a->hd] = -1;
	ft_more_med_pa(pk);
	return (0);
}

void			ft_part_a(t_pack *pk)
{
	ft_more_med_pa(pk);
	ft_a_sort_3(pk);
	if (pk->b->ln)
		ft_b_sort_3(pk);
	ft_add_delimiter(pk->a, ft_min(pk->a));
	if (ft_check_sorted(pk->a, pk->a->hd, 0))
		return ;
	pk->a->m[pk->a->hd] = 0;
	if (ft_count(pk->a) > 3)
	{
		while (!pk->a->m[pk->a->hd])
		{
			if (pk->a->p[pk->a->hd] == pk->a->p[pk->a->prev[pk->a->hd]] + 1)
				ft_ra(pk->a, pk->o);
			if (!pk->a->m[pk->a->hd])
				ft_pb(pk->a, pk->b, pk->o);
		}
	}
	ft_part_a(pk);
}
