/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_write_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:40 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:43:45 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_add_ops(t_ops *o, char op)
{
	o->d[o->hd & OPS_M] = op;
	o->hd++;
}

void			ft_remove_ops(t_ops *o)
{
	o->d[o->hd & OPS_M] = 0;
	if (o->hd > 0)
		o->hd--;
}

char			ft_get_ops(t_ops *o)
{
	return (o->d[o->hd & OPS_M]);
}

void			ft_sa(t_stack *a, t_ops *o)
{
	ft_s(a);
	ft_add_ops(o, 1);
}

void			ft_sb(t_stack *b, t_ops *o)
{
	ft_s(b);
	ft_add_ops(o, 2);
}
