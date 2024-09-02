/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:49:37 by moni              #+#    #+#             */
/*   Updated: 2024/09/02 12:42:39 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


t_stack	*new_node(char *av, t_info *info)
{
	t_stack		*new;
	int			number;

	number = ft_atoi(av);
	new = malloc(sizeof(t_stack));
	if(!new)
	{
		return NULL;
	}
	new->content = number;
	info->size++;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	
	new->next = *stack;
	if(*stack)
		(*stack)->prev = new;

	*stack = new;
}

void	push_back(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	if(!new)
		return ;

	if (!*stack)
	{
		*stack = new;
		return ;
	}

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = new;
	new->prev = temp;
}

t_stack		*pop(t_stack **stack)
{
	t_stack	*tmp;

	if(!stack ||!*stack)
		return NULL;

	
	tmp = *stack;
	*stack = (*stack)->next;
	if(*stack)
		(*stack)->prev = NULL;
	
	return (tmp);//on recupere ladresse
}

