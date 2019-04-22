/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:44:10 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:44:12 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				ft_bck_em(t_stack *s)
{
	int i;

	i = cir_b(s->hd - 1, s->max);
	while (s->next[i])
		i = cir_b(i - 1, s->max);
	return (i);
}

void			ft_init_new(t_stack *s)
{
	s->hd = 1;
	s->next[1] = 1;
	s->prev[1] = 1;
}

void			ft_add_new(t_stack *s)
{
	int i;

	if (s->ln)
	{
		i = ft_bck_em(s);
		s->next[i] = s->hd;
		s->prev[i] = s->prev[s->hd];
		s->next[s->prev[s->hd]] = i;
		s->prev[s->hd] = i;
		s->hd = i;
	}
	else
		ft_init_new(s);
	s->ln++;
}

void			ft_remove(t_stack *s)
{
	int prev;
	int next;

	prev = s->prev[s->hd];
	next = s->next[s->hd];
	s->next[prev] = next;
	s->prev[next] = prev;
	s->next[s->hd] = 0;
	s->prev[s->hd] = 0;
	s->hd = next;
	s->ln--;
}
