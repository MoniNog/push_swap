/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:54:36 by moni              #+#    #+#             */
/*   Updated: 2024/09/06 20:18:48 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	swap(t_stack **stack)
{
	t_stack		*first;
	t_stack		*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	if ((*stack)->next == NULL)
	{
		first->prev = *stack;
		(*stack)->next = first;
		(*stack)->prev = NULL;
		first->next = NULL;
	}
	else
	{
		first->prev = *stack;
		tmp = (*stack)->next;
		(*stack)->next->prev = first;
		(*stack)->prev = NULL;
		(*stack)->next = first;
		first->next = tmp;
	}
}

void	sa(t_stack **stack_a, t_info *info)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	info->move++;
}

void	sb(t_stack **stack_b, t_info *info)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	info->move++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	info->move++;
}
