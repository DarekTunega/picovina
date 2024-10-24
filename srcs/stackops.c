/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:23:32 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 16:42:44 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

void	stack_addfront(t_stack **stack, t_stack *new)
{
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

int	check_dupe(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

static void	push(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (!*stackb)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	if (*stackb)
		(*stackb)->prev = NULL;
	tmp->next = NULL;
	stack_addfront(stacka, tmp);
}

void	pa(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("pa\n", 1);
	push(stacka, stackb);
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("pb\n", 1);
	push(stackb, stacka);
}
