/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:44:28 by moni              #+#    #+#             */
/*   Updated: 2024/08/28 11:55:20 by moni             ###   ########.fr       */
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


// int	cost_to_bring_up(t_stack **stack, t_stack *current, t_node *price)
// {
// 	int	price;

// 	price = 0;

// 	si je suis dans la partie haute


// 	while (stack)
// 	{
// 		if ((stack_size(stack) - index_of_number_on_stack(stack, current)) - (stack_size(stack) / 2))
// 			price->rrb++;
// 		if ((stack_size(stack) - index_of_number_on_stack(stack, current)) > (stack_size(stack) / 2))
// 			price->rb++;
// 		stack = (*stack)->next;
// 	}
// 	return (price);
// }

int index_of_number_on_stack(t_stack **stack, t_stack *number)
{
	int			count;
	t_stack		*current;
	
	count = 0;
	current = *stack;

	while (current != NULL)
	{
		if (current == number)
			return (count);
		count++;
		current = current->next;
	}
	return (-1);
}

int	stack_size(t_stack *number)
{
	int	count;

	count = 0;
	while (number)
	{
		number = number->next;
		count++;
	}
	number->size = count;
	return (count);
}