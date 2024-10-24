/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:12:56 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 17:59:23 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/anarchy.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_non_digit( char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!isddigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	stack_init(int argc, char **argv, t_stack **stacka)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');

		if (!args[j])
		{
			free(args);
			return (0);
		}
		while (args[j])
		{
			if (ft_atol(args[j]) > INT_MAX || ft_atol(args[j]) < INT_MIN
				|| is_non_digit(args[j]))
			{
				return (free_split(args), 0);
			}
			stack_addback(stacka, stack_new(ft_atoi(args[j])));
			j++;
		}
		free_split(args);
		i++;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		return (0);
	if (!stack_init(argc, argv, &stacka) || check_dupe(stacka))
	{
		error_exit(&stacka, &stackb);
		return (1);
	}
	if (!is_sorted(stacka))
	{
		if (stack_size(stacka) <= 5)
			short_sort(&stacka, &stackb);
		else
			radix_sort(&stacka, &stackb);
	}
	free_stack(&stacka);
	free_stack(&stackb);
	return (0);
}
