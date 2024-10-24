/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_thingies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:16:17 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 15:33:37 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

static void	swap_first_two(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

void	sa(t_stack **stack)
{
	ft_putstr_fd("sa\n", 1);
	swap_first_two(stack);
}

void	sb(t_stack **stack)
{
	ft_putstr_fd("sb\n", 1);
	swap_first_two(stack);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	swap_first_two(stacka);
	swap_first_two(stackb);
	ft_putstr_fd("ss\n", 1);
}
