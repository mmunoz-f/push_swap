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

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

/**
 *	stack_utils.c
 */

t_stack			*add_back_stack(int n, t_stack *a);

t_stack			*add_front_stack(int n, t_stack *a);

t_stack			*remove_front_stack(t_stack *a);

t_stack			*remove_back_stack(t_stack *a);

t_stack			*cpy_stack(t_stack *a);

/**
 *	push_swap_utils.c
 */

void			read_stack(t_stack *a, char *stack_name);

int				is_ordered(t_stack *a);

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

void			solve_push_swap(t_stack *a, int entry_point);

void			leave_solve(t_stack *a);

/**
 * 	sort_three.c
 */

void			sort_three(t_stack **a);

/**
 * 	sort_greater.c
 */

void			sort_greater(t_stack **a, int len_a);

/**
 * 	sort_great_utils.c
 */

int				steps_to_min(t_stack *a, int mid_value);

#endif
