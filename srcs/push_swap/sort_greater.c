/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:27:38 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/26 19:33:18 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static unsigned int	number_of_chunks(t_stack *a)
{
	unsigned int	len;
	unsigned int	chunks;

	len = stack_len(a);
	if (len <= 20)
		chunks = 2;
	else if (len < 100)
		chunks = 5;
	else if (len < 500)
		chunks = 8;
	else
		chunks = 11;
	return (chunks);
}

static void	pass_chunks(t_stack **a, t_stack **b, t_stack **cmds, unsigned int chunk_len)
{
	t_stack			*tmp;
	t_stack			*tmp2;
	t_stack			*tmp_cmds;

	tmp = cpy_stack(*a, stack_len(*a));
	tmp2 = 0;
	tmp_cmds = 0;
	while (stack_len(tmp) > chunk_len)
	{
		if (chunk_len % 2)
			pass_nmax(a, b, cmds, chunk_len / 2 + 1);
		else
			pass_nmax(a, b, cmds, chunk_len / 2);
		pass_nmax(&tmp, &tmp2, &tmp_cmds, chunk_len);
	}
	pass_nmin(a, b, cmds, stack_len(tmp));
	while (*a)
		pass_nmin(a, b, cmds, chunk_len / 2);
	free_stack(tmp);
	free_stack(tmp2);
	free_stack(tmp_cmds);
}

void	sort_greater(t_stack **a, t_stack **b, t_stack **cmds)
{
	unsigned int	chunk_len;

	chunk_len = stack_len(*a) / number_of_chunks(*a);
	pass_chunks(a, b, cmds, chunk_len);
	read_stack(*a, "Init stack a\n");
	read_stack(*b, "Init stack b\n");
}
