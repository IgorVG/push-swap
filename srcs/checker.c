/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:46:39 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/09 18:46:43 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static char		*ft_ops(int i)
{
	if (i == 1)
		return ("sa");
	else if (i == 2)
		return ("sb");
	else if (i == 3)
		return ("ss");
	else if (i == 4)
		return ("ra");
	else if (i == 5)
		return ("rb");
	else if (i == 6)
		return ("rr");
	else if (i == 7)
		return ("rra");
	else if (i == 8)
		return ("rrb");
	else if (i == 9)
		return ("rrr");
	else if (i == 10)
		return ("pa");
	else if (i == 11)
		return ("pb");
	return (0);
}

int				ft_op_parse(char *line)
{
	int i;

	i = 1;
	while (i < 12)
	{
		if (!ft_strcmp(line, ft_ops(i)))
			return (i);
		i++;
	}
	return (0);
}

int				ft_check_is_sorted(t_stack *s, int hd)
{
	int i;

	i = 0;
	while (++i < s->ln)
	{
		if (s->d[hd] < s->d[s->next[hd]])
			hd = s->next[hd];
		else
			return (0);
	}
	return (1);
}

void			ft_do_ops(t_stack *s_a, t_stack *s_b, int op)
{
	if (op == 1)
		ft_s(s_a);
	else if (op == 2)
		ft_s(s_b);
	else if (op == 3)
		ft_s_s(s_a, s_b);
	else if (op == 10)
		ft_p_a(s_a, s_b);
	else if (op == 11)
		ft_p_b(s_a, s_b);
	else if (op == 4)
		ft_r(s_a);
	else if (op == 5)
		ft_r(s_b);
	else if (op == 6)
		ft_r_r(s_a, s_b);
	else if (op == 7)
		ft_rev(s_a);
	else if (op == 8)
		ft_rev(s_b);
	else if (op == 9)
		ft_rrev(s_a, s_b);
}

int				main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;
	char	*line;
	int		rd;
	int		op;

	ft_init_stack(&s_a);
	ft_in_read(argc, argv, &s_a);
	ft_init_stack(&s_b);
	s_b.max = s_a.max;
	while ((rd = get_next_line_lite(0, &line)))
	{
		if (!(op = ft_op_parse(line)))
			ft_error(-2);
		free(line);
		line = NULL;
		ft_do_ops(&s_a, &s_b, op);
	}
	if (!rd && line)
		free(line);
	if (ft_check_is_sorted(&s_a, s_a.hd) && !s_b.ln)
		ft_sorted(1);
	ft_sorted(0);
	return (0);
}
