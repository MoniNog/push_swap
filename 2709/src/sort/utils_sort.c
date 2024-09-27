/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:07 by moni              #+#    #+#             */
/*   Updated: 2024/09/21 19:29:23 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_index(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_array(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->content;
	i = 0;
	stack->min_index = 0;
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
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	max = tmp->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}
