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

void	add_to_stack(int n, t_stack *a)
{
	if (!a)
	{
		a = ft_calloc(1, sizeof(t_stack));
		a->n = n;
	}
	else
	{
		while (a->next)
			a = a->next;
		a->next = ft_calloc(1, sizeof(t_stack));
		a = a->next;
		a->n = n;
	}
}

void	read_stack(t_stack *a)
{
	while (a)
	{
		ft_putnbr_fd(a->n, 0);
		a = a->next;
	}
	ft_putchar_fd('\n', 0);
}
