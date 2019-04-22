/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:44:31 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:44:32 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int			ft_part(int *d, int h, int e)
{
	int i;
	int j;
	int x;

	x = d[e];
	i = h - 1;
	j = h;
	while (j < e)
	{
		if (d[j] < x)
			ft_swap(&d[++i], &d[j]);
		j++;
	}
	ft_swap(&d[++i], &d[e]);
	return (i);
}

static int			ft_rand_part(int *d, int h, int e)
{
	int q;

	q = (e + h) / 2;
	ft_swap(&d[q], &d[e]);
	return (ft_part(d, h, e));
}

int					ft_med(int *d, int h, int e, int i)
{
	int q;
	int k;

	if (h == e)
		return (d[h]);
	q = ft_rand_part(d, h, e);
	k = q - h + 1;
	if (i == k)
		return (d[q]);
	else if (i < k)
		return (ft_med(d, h, q - 1, i));
	else
		return (ft_med(d, q + 1, e, i - k));
}

void				ft_stk_to_arr(t_stack *a, int *d)
{
	int i;
	int h;

	i = 0;
	h = a->hd;
	while (i < a->ln)
	{
		d[i] = a->d[h];
		h = a->next[h];
		i++;
	}
}

int					ft_median(t_stack *s)
{
	int	med;
	int	d[s->ln];
	int	i;

	if ((s->ln & 1))
		i = (s->ln / 2) + 1;
	else
		i = s->ln / 2;
	ft_stk_to_arr(s, d);
	med = ft_med(d, 0, (s->ln - 1), i);
	return (med);
}
