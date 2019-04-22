/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:30:38 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/15 09:30:41 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		ft_rot_sorted(t_pack *pk, int hd)
{
	while (pk->b->d[pk->b->hd] != pk->b->d[hd])
		ft_rb(pk->b, pk->o);
	while (pk->b->ln)
		ft_pa(pk->a, pk->b, pk->o);
	while (!pk->a->m[pk->a->hd])
		ft_ra(pk->a, pk->o);
}

void			ft_b_sort_3(t_pack *pk)
{
	int hd;
	int min;

	if ((hd = ft_check_sorted_rot(pk->b, 1)))
		ft_rot_sorted(pk, hd);
	else
	{
		min = ft_min(pk->b);
		while (pk->b->d[pk->b->hd] != min)
			ft_rb(pk->b, pk->o);
		ft_pa(pk->a, pk->b, pk->o);
		ft_ra(pk->a, pk->o);
		min = ft_min(pk->b);
		while (pk->b->d[pk->b->hd] != min)
			ft_rb(pk->b, pk->o);
		ft_pa(pk->a, pk->b, pk->o);
		ft_ra(pk->a, pk->o);
		ft_pa(pk->a, pk->b, pk->o);
		ft_ra(pk->a, pk->o);
	}
}

static int		ft_sub_sorted(t_pack *pk)
{
	int i;

	i = ft_count(pk->a);
	if (i < 4 && i)
		pk->a->m[pk->a->hd] = 0;
	else
		return (-1);
	if (ft_check_sorted_k(pk->a, pk->a->hd, i, 0))
	{
		ft_ra(pk->a, pk->o);
		while (!pk->a->m[pk->a->hd])
			ft_ra(pk->a, pk->o);
		return (-1);
	}
	return (i);
}

static void		ft_sara(t_pack *pk)
{
	ft_sa(pk->a, pk->o);
	ft_ra(pk->a, pk->o);
}

void			ft_a_sort_3(t_pack *pk)
{
	int i;

	if ((i = ft_sub_sorted(pk)) == -1)
		return ;
	if (i == 3 && pk->a->d[pk->a->hd] < pk->a->d[pk->a->next[pk->a->hd]]
		&& pk->a->d[pk->a->hd] < pk->a->d[pk->a->next[pk->a->next[pk->a->hd]]])
		ft_ra(pk->a, pk->o);
	else if (i == 3 && pk->a->d[pk->a->hd] > pk->a->d[pk->a->next[pk->a->hd]]
		&& pk->a->d[pk->a->hd] < pk->a->d[pk->a->next[pk->a->next[pk->a->hd]]])
		ft_sara(pk);
	else if (i == 3)
		ft_pb(pk->a, pk->b, pk->o);
	if (pk->a->d[pk->a->hd] > pk->a->d[pk->a->next[pk->a->hd]])
		ft_sa(pk->a, pk->o);
	if (!pk->a->m[pk->a->hd]
		|| pk->a->p[pk->a->hd] == pk->a->p[pk->a->prev[pk->a->hd]] + 1)
		ft_ra(pk->a, pk->o);
	if (pk->b->ln > 3 && pk->b->d[pk->b->hd] < pk->a->d[pk->a->hd])
		ft_pa(pk->a, pk->b, pk->o);
	if (pk->a->p[pk->a->hd] == pk->a->p[pk->a->prev[pk->a->hd]] + 1)
		ft_ra(pk->a, pk->o);
	if (pk->b->ln > 3)
		ft_pa(pk->a, pk->b, pk->o);
	if (pk->a->p[pk->a->hd] == pk->a->p[pk->a->prev[pk->a->hd]] + 1)
		ft_ra(pk->a, pk->o);
}
