/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:56 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:46:57 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_parse_multi_digits(t_stack *s, int rc, char **rv)
{
	int i;

	i = 0;
	while (++i < rc)
	{
		if (ft_atoli(rv[i]) > INT_MAX || ft_atoli(rv[i]) < INT_MIN)
			ft_error(-2);
		s->d[i & STACK_M] = ft_atoi(rv[i]);
		s->prev[i & STACK_M] = i - 1;
		s->next[i & STACK_M] = 1;
		s->next[(i - 1) & STACK_M] = i;
	}
	i--;
	s->max = i;
	s->ln = i;
	s->prev[1] = s->max;
}

void	ft_parse_one_string(t_stack *s, char *str)
{
	int i;

	i = 1;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str)
		{
			if (ft_atoli(str) > INT_MAX || ft_atoli(str) < INT_MIN)
				ft_error(-2);
			s->d[i & STACK_M] = ft_atoi(str);
			s->prev[i & STACK_M] = i - 1;
			s->next[i & STACK_M] = 1;
			s->next[(i - 1) & STACK_M] = i;
			i++;
		}
		while (*str && (ft_isdigit(*str) || *str == '-' || *str == '+'))
			str++;
	}
	i--;
	s->max = i;
	s->ln = i;
	s->prev[1] = s->max;
}

void	ft_in_read(int argc, char **argv, t_stack *s_a)
{
	int i;

	i = 0;
	ft_in_check(argc, argv);
	if (argc == 2)
		ft_parse_one_string(s_a, argv[1]);
	else
		ft_parse_multi_digits(s_a, argc, argv);
	ft_check_dup(s_a);
}
