/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:25:38 by igarbuz           #+#    #+#             */
/*   Updated: 2019/04/15 10:25:40 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# include "libft.h"

/*
** STACK_SIZE TO BE MAXIMAZED FOR 100 000 : 400 KB
** STACK   : 0x80000, 0x40000, 0x20000, 0x10000, 0x8000, 0x4000, 0x2000, 0x1000
** STACK_M : 0x7ffff, 0x3ffff, 0x1ffff, 0x0ffff, 0x7fff, 0x3fff, 0x1fff, 0x0fff;
*/
# define STACK		0x4000
# define STACK_M	0x3fff
# define OPS_S		0x10000
# define OPS_M		0x0ffff

# define QS_PART	6
# define ABS(arg)	((arg >= 0) ? arg : -arg)

typedef struct		s_stack
{
	int		d[STACK];
	int		p[STACK];
	char	m[STACK];
	int		next[STACK];
	int		prev[STACK];
	int		max;
	int		hd;
	int		ln;
}					t_stack;

typedef struct		s_ops
{
	unsigned char	d[OPS_S];
	int				hd;
}					t_ops;

typedef struct		s_pack
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*o;
}					t_pack;

/*
** ft_in_check.c
*/
void				ft_in_check(int rc, char **rv);
void				ft_check_dup(t_stack *st);
/*
** ops_1.c
*/
void				ft_swap(int *a, int *b);
void				ft_swapc(char *a, char *b);
void				ft_s(t_stack *s);
void				ft_s_s(t_stack *a, t_stack *b);
void				ft_r(t_stack *s);
/*
** ops_2.c
*/
void				ft_r_r(t_stack *a, t_stack *b);
void				ft_rev(t_stack *s);
void				ft_rrev(t_stack *a, t_stack *b);
void				ft_p_a(t_stack *a, t_stack *b);
void				ft_p_b(t_stack *a, t_stack *b);
/*
** ops_write_1.c
*/
void				ft_add_ops(t_ops *o, char op);
void				ft_remove_ops(t_ops *o);
char				ft_get_ops(t_ops *o);
void				ft_sa(t_stack *a, t_ops *o);
void				ft_sb(t_stack *b, t_ops *o);
/*
** ops_write_2.c
*/
void				ft_ss(t_stack *a, t_stack *b, t_ops *o);
void				ft_ra(t_stack *a, t_ops *o);
void				ft_rb(t_stack *b, t_ops *o);
void				ft_rr(t_stack *a, t_stack *b, t_ops *o);
void				ft_rra(t_stack *a, t_ops *o);
/*
** ops_write_3.c
*/
void				ft_rrb(t_stack *b, t_ops *o);
void				ft_rrr(t_stack *a, t_stack *b, t_ops *o);
void				ft_pa(t_stack *a, t_stack *b, t_ops *o);
void				ft_pb(t_stack *a, t_stack *b, t_ops *o);
/*
** print_ops.c
*/
void				ft_print_ops(unsigned char *b);
/*
** stack_init.c
*/
void				ft_init_stack(t_stack *s);
void				ft_init_ops(t_ops *o);
void				ft_pack_init(t_pack *pk, t_stack *a, t_stack *b, t_ops *o);
/*
** ft_read.c
*/
void				ft_in_read(int argc, char **argv, t_stack *s_a);
void				ft_parse_one_string(t_stack *s, char *str);
void				ft_parse_multi_digits(t_stack *s, int rc, char **rv);
/*
** ft_error.c
*/
void				ft_error(int er);
void				ft_sorted(int result);
/*
** math_lib.c
*/
int					ft_min(t_stack *s);
int					ft_max(t_stack *s);
int					ft_distance_fw(t_stack *s, int elem);
int					ft_distance_bk(t_stack *s, int elem);
int					ft_count(t_stack *s);
/*
** optimiser.c
*/
void				ft_optimise_ops(t_ops *o);
/*
** push_swap.c
*/
void				ft_sort(t_stack *a, t_stack *b, t_ops *o);
/*
** ft_median.c
*/
int					ft_med(int *d, int h, int e, int i);
void				ft_stk_to_arr(t_stack *a, int *d);
int					ft_median(t_stack *s);
/*
** ft_median_k.c
*/
int					cir_f(int hd, int max);
int					cir_b(int hd, int max);
void				ft_position(t_stack *s);
int					ft_median_k(t_stack *s, int k);
void				ft_add_delimiter(t_stack *s, int med);
/*
** sub_sort.c
*/
void				ft_b_sort_3(t_pack *pk);
void				ft_a_sort_3(t_pack *pk);
/*
** sort.c
*/
void				ft_less_med_pb(t_pack *pk);
int					ft_more_med_pa(t_pack *pk);
void				ft_part_a(t_pack *pk);
/*
** stack_ops.c
*/
int					ft_bck_em(t_stack *s);
void				ft_init_new(t_stack *s);
void				ft_add_new(t_stack *s);
void				ft_remove(t_stack *s);
/*
** check_sorted.c
*/
void				ft_opt_rab(t_pack *pk, int elem, char stack);
int					ft_check_sorted(t_stack *s, int hd, int rev);
int					ft_check_sorted_rot(t_stack *s, int rev);
int					ft_check_sorted_k(t_stack *s, int hd, int k, int rev);
/*
** ft_sort_small.c
*/
void				ft_sort_small(t_pack *pk);

#endif
