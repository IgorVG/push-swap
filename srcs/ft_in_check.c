/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:49 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/16 17:43:55 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void		ft_one_str(char *s)
{
	int		i;
	char	*t;

	i = 0;
	if (*s == '\0')
		ft_error(-2);
	while (*s)
	{
		if (i >= STACK)
			ft_error(-4);
		while (*s && *s == ' ')
			s++;
		if (*s && (*s == '+' || *s == '-'))
			s++;
		if (*s && !ft_isdigit(*s))
			ft_error(-2);
		else if (*s && *s == '0')
			while ((*s && *s == '0' && (*(s + 1) && ft_isdigit(*(s + 1)))))
				s++;
		while (*s && ft_isdigit(*s) && (t = s))
			s++;
		if ((*s && *s != ' ') || (s - t) > 10)
			ft_error(-2);
		i++;
	}
}

static void		ft_separ_digits(int rc, char **rv)
{
	int i;
	int j;
	int t;

	i = 1;
	while (i < rc)
	{
		if (i >= STACK + 1)
			ft_error(-4);
		j = 0;
		if (rv[i][j] == '+' || rv[i][j] == '-')
			j++;
		if (!ft_isdigit(rv[i][j]))
			ft_error(-2);
		else if (rv[i][j] && rv[i][j] == '0')
			while (rv[i][j] && rv[i][j] == '0' && rv[i][j + 1] 
				&& ft_isdigit(rv[i][j + 1]))
				j++;
		t = j;
		while (rv[i][j] && ft_isdigit(rv[i][j]))
			j++;
		if (rv[i][j] || (j - t) > 10)
			ft_error(-2);
		i++;
	}
}

void			ft_in_check(int rc, char **rv)
{
	if (rc == 1)
		ft_error(-1);
	else if (rc == 2)
		ft_one_str(rv[1]);
	else
		ft_separ_digits(rc, rv);
}

void			ft_check_dup(t_stack *s)
{
	int i;
	int j;

	if (s->ln > 1)
	{
		i = 1;
		while (i <= s->ln)
		{
			j = i;
			while (++j <= s->ln)
				if (s->d[i] == s->d[j])
					ft_error(-2);
			i++;
		}
	}
}
