/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:59:32 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/21 18:01:01 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *line, int errnum)
{
	ft_putstr_fd(line, STDERR_FILENO);
	exit(errnum);
}

static int	repeat_numbers(t_stack *a)
{
	t_stack	*tmp;
	int		num;

	while (a)
	{
		tmp = a->next;
		num = a->n;
		while (tmp)
		{
			if (tmp->n == num)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

t_stack	*init_stack(int argc, char **ints)
{
	t_stack	*a;
	int		n;

	a = 0;
	while (argc--)
	{
		if (!(ft_strchr("-0123456789", **ints)))
			return (0);
		n = ft_atoi(*ints);
		if (**ints == '-')
			(*ints)++;
		while (ft_strchr("0123456789", **ints) && **ints)
			(*ints)++;
		if (**ints)
			return (0);
		a = add_back_stack(n, a);
		ints++;
	}
	if (repeat_numbers(a))
		return (0);
	return (a);
}
