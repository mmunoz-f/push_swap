/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:59:32 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/29 19:47:13 by mmunoz-f         ###   ########.fr       */
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

static int	greater_than_long(char *string)
{
	unsigned long long int	n;
	int						negative;

	negative = 0;
	n = 0;
	if (*string == '-')
	{
		negative = 1;
		string++;
	}
	while (ft_strchr("0123456789", *string) && *string)
	{
		n = n * 10 + ((*string) - 48);
		string++;
		if ((!negative && n > __INT_MAX__)
			|| (negative && (n - 1) > __INT_MAX__))
			return (1);
	}
	return (0);
}

static void	init_stack(int argc, char **ints, t_stack **a)
{
	int		n;

	while (argc--)
	{
		if (greater_than_long(*ints) || !(ft_strchr("-+0123456789", **ints)))
			error_exit("Error\n", 1);
		n = ft_atoi(*ints);
		if (**ints == '-' || **ints == '+')
		{
			(*ints)++;
			if (!**ints)
				error_exit("Error\n", 1);
		}
		while (ft_strchr("0123456789", **ints) && **ints)
			(*ints)++;
		if (**ints)
			error_exit("Error\n", 1);
		*a = add_back_stack(n, *a);
		ints++;
	}
	if (repeat_numbers(*a))
		error_exit("Error\n", 1);
}

void	charge_arguments(int argc, char **argv, t_stack **a)
{
	char			**split;
	char			**tmp1;
	char			**tmp2;
	unsigned int	size;

	while (argc--)
	{
		split = ft_split(*argv, " ");
		size = 0;
		while (split[size])
			size++;
		tmp1 = malloc(sizeof(char *) * (size + 1));
		tmp1 = ft_memcpy(tmp1, split, sizeof(char *) * (size + 1));
		tmp2 = split;
		init_stack(size, split, a);
		while (size)
			free(tmp1[--size]);
		free(tmp1);
		free(tmp2);
		argv++;
	}
}
