/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_joke.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:30:47 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 17:03:01 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	error_exit(t_stack **stacka, t_stack **stackb)
{
	free_stack(stacka);
	free_stack(stackb);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
