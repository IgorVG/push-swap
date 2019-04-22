/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:45:07 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:45:09 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_r_r(t_stack *a, t_stack *b)
{
	ft_r(a);
	ft_r(b);
}

void			ft_rev(t_stack *s)
{
	if (s->ln > 1)
		s->hd = s->prev[s->hd];
}

void			ft_rrev(t_stack *a, t_stack *b)
{
	ft_rev(a);
	ft_rev(b);
}

void			ft_p_a(t_stack *a, t_stack *b)
{
	if (b->ln)
	{
		ft_add_new(a);
		a->d[a->hd] = b->d[b->hd];
		a->p[a->hd] = b->p[b->hd];
		a->m[a->hd] = b->m[b->hd];
		ft_remove(b);
	}
}

void			ft_p_b(t_stack *a, t_stack *b)
{
	if (a->ln)
	{
		ft_add_new(b);
		b->d[b->hd] = a->d[a->hd];
		b->p[b->hd] = a->p[a->hd];
		b->m[b->hd] = a->m[a->hd];
		ft_remove(a);
	}
}
