/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimiser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:13:25 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/16 12:13:29 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		ft_check_to_remove(unsigned char i, unsigned char j)
{
	if ((i == 6 && j == 9) || (i == 9 && j == 6)
		|| (i == 4 && j == 7) || (i == 7 && j == 4)
		|| (i == 5 && j == 8) || (i == 8 && j == 5)
		|| (i == 1 && j == 1) || (i == 2 && j == 2)
		|| (i == 10 && j == 11) || (i == 11 && j == 10))
		return (1);
	return (0);
}

static void		ft_parse_ops(t_ops *o, unsigned char *b, int i, int j)
{
	while (i < o->hd)
	{
		if (ft_check_to_remove(o->d[i], b[j]))
		{
			b[j] = 0;
			if (j > 0)
				j--;
		}
		else if ((o->d[i] == 1 && b[j] == 2) || (o->d[i] == 2 && b[j] == 1))
			b[j] = 3;
		else if ((o->d[i] == 4 && b[j] == 5) || (o->d[i] == 5 && b[j] == 4))
			b[j] = 6;
		else if ((o->d[i] == 7 && b[j] == 8) || (o->d[i] == 8 && b[j] == 7))
			b[j] = 9;
		else
		{
			while (b[j])
				j++;
			b[j] = o->d[i];
		}
		i++;
	}
}

void			ft_optimise_ops(t_ops *o)
{
	unsigned char	b[o->hd + 1];
	int				i;
	int				j;

	if (o->d[(o->hd + 1) & OPS_M])
		ft_error(-9);
	ft_bzero((void *)b, o->hd + 1);
	i = 0;
	j = 0;
	b[j] = o->d[i];
	i++;
	ft_parse_ops(o, b, i, j);
	ft_print_ops(b);
}
