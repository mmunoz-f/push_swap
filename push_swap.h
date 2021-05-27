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

# include "libft/libft.h"

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}	t_stack;

void	read_stack(t_stack *a, char *stack_name);

t_stack	*add_back_stack(int n, t_stack *a);

t_stack	*add_front_stack(int n, t_stack *a);

t_stack	*remove_front_stack(t_stack *a);

t_stack	*remove_back_stack(t_stack *a);

void	swap_op(t_stack *a);

void	push_op(t_stack **a, t_stack **b);

void	rotate_op(t_stack **a);

void	reverse_rotate_op(t_stack **a);

#endif
