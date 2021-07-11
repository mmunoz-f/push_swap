/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:36:32 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/05/26 19:36:32 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_back_stack(int n, t_stack *a)
{
	t_stack	*start;

	if (!a)
	{
		a = ft_calloc(1, sizeof(t_stack));
		a->n = n;
		start = a;
	}
	else
	{
		start = a;
		while (a->next)
			a = a->next;
		a->next = ft_calloc(1, sizeof(t_stack));
		a = a->next;
		a->n = n;
	}
	return (start);
}

t_stack	*add_front_stack(int n, t_stack *a)
{
	t_stack	*start;

	start = ft_calloc(1, sizeof(t_stack));
	start->n = n;
	start->next = a;
	return (start);
}

t_stack	*remove_front_stack(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (a);
	tmp = a;
	a = a->next;
	free(tmp);
	return (a);
}

t_stack	*remove_back_stack(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!a)
		return (a);
	tmp = a;
	start = a;
	while (a->next && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next)
			a = a->next;
	}
	if ((!a->next))
		start = 0;
	a->next = 0;
	free(tmp);
	return (start);
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
