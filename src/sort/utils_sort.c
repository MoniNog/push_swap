/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:07 by moni              #+#    #+#             */
/*   Updated: 2024/09/06 19:52:13 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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

int		find_max(t_stack *stack)
{
	int		max;
	
	max = stack->content;
	while (stack->next)// besoin de 2 pour comparer
	{
		if (max < stack->next->content)
			max = stack->next->content;
		stack = stack->next;
	}
	return(max);
}

int	stack_size(t_stack **stack)
{
	int	count;

	count = 0;
	while ((*stack)->next)
	{
		count++;
		*stack = (*stack)->next;
	}
	// (*stack)->size = malloc(sizeof(t_stack));
	//count = (*stack)->size;
	return (count);
}

// // // int	cost_to_bring_up(t_stack **stack, t_stack *current, t_node *price)
// // // {
// // 	int	price;
// // 	price = 0;
// // 	si je suis dans la partie haute
// // 	while (stack)
// // 	{
// // 		if ((stack_size(stack) - index_of_number_on_stack(stack, current)) - (stack_size(stack) / 2))
// // 			price->rrb++;
// // 		if ((stack_size(stack) - index_of_number_on_stack(stack, current)) > (stack_size(stack) / 2))
// // 			price->rb++;
// // 		stack = (*stack)->next;
// // 	}
// // 	return (price);
// // }

// int index_of_number_on_stack(t_stack **stack, t_stack *number)
// {
// 	int			count;
// 	t_stack		*current;
// 	count = 0;
// 	current = *stack;
// 	while (current != NULL)
// 	{
// 		if (current == number)
// 			return (count);
// 		count++;
// 		current = current->next;
// 	}
// 	return (-1);
// }
