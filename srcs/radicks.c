/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radicks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:18:18 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 15:38:31 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

static int	find_max(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = find_max(stack);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **stacka, t_stack **stackb)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	size = stack_size(*stacka);
	max_bits = printf("%d",get_max_bits(*stacka));
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stacka)->value >> i) & 1) == 1)
				ra(stacka);
			else
				pb(stacka, stackb);
			j++;
		}
		while (*stackb)
			pa(stacka, stackb);
		i++;
	}
}

int	isddigit(int c)
{
	return (c >= '0' && c <= '9');
}
