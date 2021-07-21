/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:21:49 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/05/26 19:21:49 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include "libft/libft.h"

# define M_SA 1
# define M_SB 2
# define M_SS 3
# define M_PA 4
# define M_PB 5
# define M_RA 6
# define M_RB 7
# define M_RR 8
# define M_RRA 9
# define M_RRB 10
# define M_RRR 11

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

/**
 * 	push_swap.c
 */

t_stack			*init_stack(int argc, char **ints);

void			error_exit(char *line, int errnum);

/**
 *	stack_utils.c
 */

t_stack			*add_back_stack(int n, t_stack *a);

t_stack			*add_front_stack(int n, t_stack *a);

t_stack			*remove_front_stack(t_stack *a);

t_stack			*remove_back_stack(t_stack *a);

t_stack			*cpy_stack(t_stack *a, int n);

/**
 *	push_swap_utils.c
 */

void			read_stack(t_stack *a, char *stack_name);

int				is_ordered(t_stack *a, int mode);

void			free_stack(t_stack *a);

unsigned int	stack_len(t_stack *a);

void			merge_stack(t_stack *a, t_stack *b);

/**
 * 	push_swap_operations.c
 */

void			swap_op(t_stack *a);

void			push_op(t_stack **a, t_stack **b);

void			rotate_op(t_stack **a);

void			reverse_rotate_op(t_stack **a);

/**
 * 	push_swap_solve.c
 */

void			solve_push_swap(t_stack **a, t_stack **b, t_stack **cmds);

void			leave_solve(t_stack *a, t_stack *cmds);

void			print_cmds(t_stack **cmds);

/**
 * 	sort_three.c
 */

void			sort_three(t_stack **a, t_stack **cmds, int stack);

void			sort_reverse_three(t_stack **a, t_stack **cmds, int stack);

/**
 * 	sort_greater.c
 */

void			sort_greater(t_stack **a, t_stack **b, t_stack **cmds);

/**
 * 	sort_great_utils.c
 */

int				steps_to_min(t_stack *a, int mid_value);

/**
 * 	solve_six.c
 */

void			solve_six(t_stack **a, t_stack **a_cmds);

/**
 * 	simple_sort.c
 */

void			simple_reverse_solve(t_stack **b, t_stack **cmds);

void			simple_solve(t_stack **a, t_stack **cmds);

#endif
