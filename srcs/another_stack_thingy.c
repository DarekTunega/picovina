/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_stack_thingy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:29:10 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 15:33:37 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	stack_addback(stack, tmp);
}

void	ra(t_stack **stack)
{
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	rotate(stacka);
	rotate(stackb);
	ft_putstr_fd("rr\n", 1);
}
