/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:55:24 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 15:44:01 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int				ft_min(t_stack *s)
{
	int i;
	int min;
	int hd;

	min = s->d[s->hd];
	i = 0;
	hd = s->next[s->hd];
	while (++i < s->ln)
	{
		if (s->d[hd] < min)
			min = s->d[hd];
		hd = s->next[hd];
	}
	return (min);
}

int				ft_max(t_stack *s)
{
	int i;
	int max;
	int hd;

	max = s->d[s->hd];
	i = 0;
	hd = s->next[s->hd];
	while (++i < s->ln)
	{
		if (s->d[hd] > max)
			max = s->d[hd];
		hd = s->next[hd];
	}
	return (max);
}

int				ft_distance_fw(t_stack *s, int elem)
{
	int hd;
	int i;

	i = 0;
	hd = s->hd;
	while (s->d[hd] != elem)
	{
		hd = s->next[hd];
		i++;
	}
	return (i);
}

int				ft_distance_bk(t_stack *s, int elem)
{
	int hd;
	int i;

	i = 0;
	hd = s->hd;
	while (s->d[hd] != elem)
	{
		hd = s->prev[hd];
		i++;
	}
	return (i);
}

int				ft_count(t_stack *s)
{
	int hd;
	int i;

	i = 0;
	hd = s->hd;
	while (!s->m[hd])
	{
		i++;
		hd = s->next[hd];
	}
	return (i);
}
