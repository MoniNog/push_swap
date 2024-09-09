/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:54:30 by moni              #+#    #+#             */
/*   Updated: 2024/09/09 20:12:15 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	rotate(t_stack**stack)
{
	t_stack		*first;
	t_stack		*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	
	first = *stack;//				first pointe sur le 1er
	*stack = (*stack)->next;//		stack pointe mtn sur le 2eme

	if ((*stack)->next == NULL)//	si que 2 elements dans la liste
	{
		first->prev = *stack;
		(*stack)->next = first;
		(*stack)->prev = NULL;
		first->next = NULL;
	}
	
	else
	{
		while ((*stack)->next != NULL)
		{
			*stack = (*stack)-> next;
		}

		last = (*stack);
		*stack = first->next;
		
		first->prev = last;
		last->next = first;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}

void	ra(t_stack **stack_a, t_info *info)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	info->move++;
}

void	rb(t_stack **stack_b, t_info *info)
{
	rotate(stack_b);
	write(1, "rb\t", 3);
	info->move++;
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	info->move++;
}
