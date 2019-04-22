/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:47:20 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:47:23 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_error(int er)
{
	if (er == -1)
		;
	else if (er == -2)
		write(1, "Error\n", 6);
	else if (er == -3)
		write(1, "Malloc error\n", 13);
	else if (er == -9)
		write(1, "Error: Operations stack is full\nExiting\n", 40);
	else if (er == -4)
		write(1, "Error: Maximal number of entry integers is exceeded\n", 52);
	exit(EXIT_FAILURE);
}

void		ft_sorted(int result)
{
	if (result == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
