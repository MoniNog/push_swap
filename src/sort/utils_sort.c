/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:07 by moni              #+#    #+#             */
/*   Updated: 2024/09/20 17:09:01 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int find_min(t_stack *stack, t_info *info)
{
	int min;
	int i = 0;
	stack->min_index = 0;
	
	min = stack->content;
	while (stack)
	{
		if (min > stack->content) 
		{
			min = stack->content;
			stack->min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return min;
}

int		find_max(t_stack *stack)
{
	int		max;
	int		i = 0;
	stack->max_index = 0;
	
	max = stack->content;
	while (stack)// besoin de 2 pour comparer
	{
		if (max < stack->content)
		{
			max = stack->content;
			stack->max_index = i;
		}
		stack = stack->next;
		i++;
	}
	return(max);
}

bool	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->content < a->next->content)
			a = a->next;
		else
			return false;
	}
	return true;
}


