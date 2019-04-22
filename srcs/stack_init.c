/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:25 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:46:29 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_init_stack(t_stack *s)
{
	int i;

	s->max = 1;
	s->hd = 1;
	s->ln = 0;
	i = 0;
	while (i < STACK)
	{
		s->d[i] = (int)0;
		s->p[i] = (int)0;
		s->next[i] = (int)0;
		s->prev[i] = (int)0;
		s->m[i] = (char)0;
		i++;
	}
}

void		ft_init_ops(t_ops *o)
{
	int i;

	ft_bzero((void *)o->d, OPS_S);
	i = -1;
	o->hd = 0;
	while (++i < OPS_S)
		o->d[i] = 0;
}

void		ft_pack_init(t_pack *pk, t_stack *a, t_stack *b, t_ops *o)
{
	pk->a = a;
	pk->b = b;
	pk->o = o;
}
