/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:45:02 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:45:04 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_swap(int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void			ft_swapc(char *a, char *b)
{
	char tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void			ft_s(t_stack *s)
{
	if (s->ln > 1)
	{
		ft_swap(&s->d[s->hd], &s->d[s->next[s->hd]]);
		ft_swap(&s->p[s->hd], &s->p[s->next[s->hd]]);
		ft_swapc(&s->m[s->hd], &s->m[s->next[s->hd]]);
	}
}

void			ft_s_s(t_stack *a, t_stack *b)
{
	ft_s(a);
	ft_s(b);
}

void			ft_r(t_stack *s)
{
	if (s->ln > 1)
		s->hd = s->next[s->hd];
}
