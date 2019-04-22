/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_write_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:49 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:43:51 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_ss(t_stack *a, t_stack *b, t_ops *o)
{
	ft_s_s(a, b);
	ft_add_ops(o, 3);
}

void			ft_ra(t_stack *a, t_ops *o)
{
	ft_r(a);
	ft_add_ops(o, 4);
}

void			ft_rb(t_stack *b, t_ops *o)
{
	ft_r(b);
	ft_add_ops(o, 5);
}

void			ft_rr(t_stack *a, t_stack *b, t_ops *o)
{
	ft_r_r(a, b);
	ft_add_ops(o, 6);
}

void			ft_rra(t_stack *a, t_ops *o)
{
	ft_rev(a);
	ft_add_ops(o, 7);
}
