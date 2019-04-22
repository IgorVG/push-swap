/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:06 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:46:09 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		ft_write_ops(char n)
{
	if (n == 1)
		write(1, "sa", 2);
	else if (n == 2)
		write(1, "sb", 2);
	else if (n == 3)
		write(1, "ss", 2);
	else if (n == 4)
		write(1, "ra", 2);
	else if (n == 5)
		write(1, "rb", 2);
	else if (n == 6)
		write(1, "rr", 2);
	else if (n == 7)
		write(1, "rra", 3);
	else if (n == 8)
		write(1, "rrb", 3);
	else if (n == 9)
		write(1, "rrr", 3);
	else if (n == 10)
		write(1, "pa", 2);
	else if (n == 11)
		write(1, "pb", 2);
}

void			ft_print_ops(unsigned char *b)
{
	int i;

	i = 0;
	while (b[i])
	{
		ft_write_ops(b[i]);
		write(1, "\n", 1);
		i++;
	}
}
