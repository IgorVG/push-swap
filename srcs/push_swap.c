/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:43:53 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 15:43:55 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_sort(t_stack *a, t_stack *b, t_ops *o)
{
	t_pack	pk;
	int		med;

	ft_pack_init(&pk, a, b, o);
	if ((med = ft_check_sorted_rot(a, 0)))
	{
		ft_opt_rab(&pk, a->d[med], 'a');
		return ;
	}
	if (a->ln < 7)
	{
		ft_sort_small(&pk);
		return ;
	}
	ft_position(a);
	if (a->ln > 3)
	{
		ft_less_med_pb(&pk);
		a->m[a->hd] = -1;
		ft_part_a(&pk);
	}
	else
		ft_a_sort_3(&pk);
}

int			main(int argc, char **argv)
{
	t_stack s_a;
	t_stack s_b;
	t_ops	ops;

	ft_init_stack(&s_a);
	ft_in_read(argc, argv, &s_a);
	ft_init_stack(&s_b);
	s_b.max = s_a.max;
	ft_init_ops(&ops);
	ft_sort(&s_a, &s_b, &ops);
	ft_optimise_ops(&ops);
	return (0);
}
