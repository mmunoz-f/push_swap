/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:58:59 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/21 19:53:15 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_op(char *line)
{
	if (!ft_strcmp(line, "pa"))
		return (M_PA);
	else if (!ft_strcmp(line, "pb"))
		return(M_PB);
	else if (!ft_strcmp(line, "sa"))
		return(M_SA);
	else if (!ft_strcmp(line, "sb"))
		return(M_SB);
	else if (!ft_strcmp(line, "ss"))
		return(M_SS);
	else if (!ft_strcmp(line, "ra"))
		return(M_RA);
	else if (!ft_strcmp(line, "rb"))
		return(M_RB);
	else if (!ft_strcmp(line, "rr"))
		return(M_RR);
	else if (!ft_strcmp(line, "rra"))
		return(M_RRA);
	else if (!ft_strcmp(line, "rrb"))
		return(M_RRB);
	else if (!ft_strcmp(line, "rrr"))
		return(M_RRR);
	return (0);
}

static int	get_op(void)
{
	char	*line;
	char	*tmp;
	char	buff[2];
	int		read_ret;
	int		op;

	line = ft_strdup("");
	if (!line)
		error_exit("Error\n", errno);
	buff[1] = 0;
	read_ret = read(STDIN_FILENO, &buff[0], 1);
	while (read_ret == 1 && buff[0] != '\n')
	{
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
		if (!line)
			error_exit("Error\n", errno);
		read_ret = read(STDIN_FILENO, &buff[0], 1);
	}
	op = 0;
	if (read_ret == 1)
		op = compare_op(line);
	free(line);
	return (op);
}

static void	execute_rr_op(t_stack **a, t_stack **b, int op)
{
	if (op == M_RRA)
		reverse_rotate_op(a);
	else if (op == M_RRB)
		reverse_rotate_op(b);
	else if (op == M_RRR)
	{
		reverse_rotate_op(a);
		reverse_rotate_op(b);
	}
}

static void	execute_op(t_stack **a, t_stack **b, int op)
{
	if (op == M_SA)
		swap_op(*a);
	else if (op == M_SB)
		swap_op(*b);
	else if (op == M_SS)
	{
		swap_op(*a);
		swap_op(*b);
	}
	else if (op == M_PA)
		push_op(a, b);
	else if (op == M_PB)
		push_op(b, a);
	else if (op == M_RA)
		rotate_op(a);
	else if (op == M_RB)
		rotate_op(b);
	else if (op == M_RR)
	{
		rotate_op(a);
		rotate_op(b);
	}
	else
		execute_rr_op(a, b, op);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		op;

	if (argc < 2)
		error_exit("Error\n", 1);
	a = 0;
	charge_arguments(argc - 1, argv + 1, &a);
	b = 0;
	read_stack(a, "Init stack A\n");
	if (!a)
		error_exit("Error\n", errno);
	op = get_op();
	while (op)
	{
		execute_op(&a, &b, op);
		read_stack(a, "Stack A\n");
		read_stack(b, "Stack B\n");
		op = get_op();
	}
	if (b || is_ordered(a, 1))
		ft_putstr_fd("KO!\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK!\n", STDOUT_FILENO);
	return (0);
}
