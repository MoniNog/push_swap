/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:44:28 by moni              #+#    #+#             */
/*   Updated: 2024/08/27 21:52:04 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		find_min(t_stack *stack)
{
	int		min;
	
	min = stack->content;
	while (stack->next)// besoin de 2 pour comparer
	{
		if (min > stack->next->content)
			min = stack->next->content;
		stack = stack->next;
	}
	return(min);
}

void	tri(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	while (*stack_a)// tant quil reste qqch dans la stack
	{
		min = find_min(*stack_a);
		while ((*stack_a)->content != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	print_stack(*stack_a, *stack_b);

	while(*stack_b)
	{
		pa(stack_a, stack_b);
	}
}