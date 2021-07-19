/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:27:38 by miguel            #+#    #+#             */
/*   Updated: 2021/07/19 18:05:10 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_stack(t_stack *a, t_stack *b)
{
	while (b)
	{
		push_op(&a, &b);
		write(STDOUT_FILENO, "pa\n", 3);
	}
}

unsigned int	stack_len(t_stack *a)
{
	unsigned int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	read_stack(t_stack *a, char *stack_name)
{
	if (stack_name)
	{
		ft_putstr_fd(stack_name, 0);
		ft_putchar_fd('\n', 0);
	}
	while (a)
	{
		ft_putnbr_fd(a->n, 0);
		ft_putchar_fd('\n', 0);
		a = a->next;
	}
	if (stack_name)
		ft_putstr_fd("------\n", 0);
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

int	is_ordered(t_stack *a, int mode)
{
	if (!a)
		return (0);
	if (mode)
	{
		while (a->next)
		{
			if (a->n > a->next->n)
				return (1);
			a = a->next;
		}
	}
	else
	{
		while (a->next)
		{
			if (a->n < a->next->n)
				return (1);
			a = a->next;
		}
	}
	return (0);
}
