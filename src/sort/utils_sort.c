/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:07 by moni              #+#    #+#             */
/*   Updated: 2024/09/09 20:37:39 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int find_min(t_stack *stack, t_info *info) {
	int min;
	int i;
	
	min = stack->content;
	info->min_index = 0;
	i = 0;
	while (stack->next)
	{
		i++;
		if (min > stack->next->content) 
		{
			min = stack->next->content;
			info->min_index = i;
		}
		stack = stack->next;
	}
	return min;
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


