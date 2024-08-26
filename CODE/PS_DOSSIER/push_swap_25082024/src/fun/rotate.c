/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:54:30 by moni              #+#    #+#             */
/*   Updated: 2024/08/26 12:41:35 by moni             ###   ########.fr       */
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
void	ra(t_stack **stack_a)//ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}
void	rb(t_stack **stack_b)//rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}
void	rr(t_stack **stack_a, t_stack **stack_b)//rr : ra et rb en même temps.
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
