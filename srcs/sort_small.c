/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:29:55 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/15 09:29:56 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_sort_small(t_pack *pk)
{
	int min;

	while (pk->a->ln > 3)
	{
		ft_opt_rab(pk, ft_min(pk->a), 'a');
		ft_pb(pk->a, pk->b, pk->o);
	}
	if ((min = ft_check_sorted_rot(pk->a, 0)))
		ft_opt_rab(pk, pk->a->d[min], 'a');
	else
	{
		ft_sa(pk->a, pk->o);
		ft_opt_rab(pk, ft_min(pk->a), 'a');
	}
	while (pk->b->ln)
	{
		ft_opt_rab(pk, ft_max(pk->b), 'b');
		ft_pa(pk->a, pk->b, pk->o);
	}
}
