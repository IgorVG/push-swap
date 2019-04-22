/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_write_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:55 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:43:58 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_rrb(t_stack *b, t_ops *o)
{
	ft_rev(b);
	ft_add_ops(o, 8);
}

void			ft_rrr(t_stack *a, t_stack *b, t_ops *o)
{
	ft_rrev(a, b);
	ft_add_ops(o, 9);
}

void			ft_pa(t_stack *a, t_stack *b, t_ops *o)
{
	ft_p_a(a, b);
	ft_add_ops(o, 10);
}

void			ft_pb(t_stack *a, t_stack *b, t_ops *o)
{
	ft_p_b(a, b);
	ft_add_ops(o, 11);
}
