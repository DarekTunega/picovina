/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   they_see_me_rollin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:27:04 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 16:34:46 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	stack_addfront(stack, tmp);
}

void	rra(t_stack **stack)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(stack);
}

void	rrb(t_stack **stack)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(stack);
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	reverse_rotate(stacka);
	reverse_rotate(stackb);
	ft_putstr_fd("rrr\n", 1);
}

void	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
