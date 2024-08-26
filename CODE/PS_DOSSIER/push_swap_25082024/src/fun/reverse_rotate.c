/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:54:26 by moni              #+#    #+#             */
/*   Updated: 2024/08/26 12:52:09 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	reverse_rotate(t_stack**stack)
{
	t_stack		*first;
	t_stack		*last;

	first = *stack;//				first pointe sur le 1er
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)-> next;
	}
	last = (*stack);//				last pointe sur le dernier
	*stack = last->prev;//			stack pointe mtn sur l'avant-dernier

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	

	if ((*stack)->next == NULL)//	si que 2 elements dans la liste
	{
		first->prev = *stack;
		(*stack)->next = first;
		(*stack)->prev = NULL;
		first->next = NULL;
	}
	
	else
	{
		last->next = first;
		first->prev = last;
		(*stack)->next = NULL;
		last->prev = NULL;

		*stack = last;
	}
}

void	rra(t_stack **stack_a)//ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)//rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)//rr : ra et rb en même temps.
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
