/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:12:25 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 15:33:37 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

static int	find_min(t_stack *stack)
{
	int	min;
	int	index;
	int	min_index;

	min = stack->value;
	index = 0;
	min_index = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

static void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > c && c > b)
		ra(stack);
	else if (b > a && a > c)
		rra(stack);
	else if (b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (c > a && a > b)
		sa(stack);
}

static void	sort_four(t_stack **stacka, t_stack **stackb)
{
	int	min_index;

	min_index = find_min(*stacka);
	if (min_index == 1)
		ra(stacka);
	else if (min_index == 2)
	{
		ra(stacka);
		ra(stacka);
	}
	else if (min_index == 3)
		rra(stacka);
	pb(stacka, stackb);
	sort_three(stacka);
	pa(stacka, stackb);
}

static void	sort_five(t_stack **stacka, t_stack **stackb)
{
	int	min_index;

	min_index = find_min(*stacka);
	if (min_index == 1)
		ra(stacka);
	else if (min_index == 2)
	{
		ra(stacka);
		ra(stacka);
	}
	else if (min_index == 3)
	{
		rra(stacka);
		rra(stacka);
	}
	else if (min_index == 4)
		rra(stacka);
	pb(stacka, stackb);
	sort_four(stacka, stackb);
	pa(stacka, stackb);
}

void	short_sort(t_stack **stacka, t_stack **stackb)
{
	if (stack_size(*stacka) == 2)
		sa(stacka);
	else if (stack_size(*stacka) == 3)
		sort_three(stacka);
	else if (stack_size(*stacka) == 4)
		sort_four(stacka, stackb);
	else if (stack_size(*stacka) == 5)
		sort_five(stacka, stackb);
}
