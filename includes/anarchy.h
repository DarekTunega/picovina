/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anarchy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunega <dtunega@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:13:09 by dtunega           #+#    #+#             */
/*   Updated: 2024/10/24 17:58:55 by dtunega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANARCHY_H
# define ANARCHY_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

char				**ft_split(char *s, char c);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
void				stack_addback(t_stack **stack, t_stack *new);
t_stack				*stack_new(int value);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stacka, t_stack **stackb);
int					get_max_bits(t_stack *stack);
long				ft_atol(char *str);
int					stack_size(t_stack *stack);
int					ft_atoi(char *str);
void				ft_putstr_fd(char *s, int fd);
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				stack_addback(t_stack **stack, t_stack *new);
void				stack_addfront(t_stack **stack, t_stack *new);
int					check_dupe(t_stack *stack);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stacka, t_stack **stackb);
void				pa(t_stack **stacka, t_stack **stackb);
void				pb(t_stack **stacka, t_stack **stackb);
int					isddigit(int c);
void				ss(t_stack **stacka, t_stack **stackb);
void				short_sort(t_stack **stacka, t_stack **stackb);
int					is_sorted(t_stack *stack);
void				radix_sort(t_stack **stacka, t_stack **stackb);
void				free_stack(t_stack **stack);
void				error_exit(t_stack **stacka, t_stack **stackb);

#endif
