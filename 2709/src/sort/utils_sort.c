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

int get_stack_size(t_stack *stack)
{
	int size = 0;
	while (stack != NULL) {
		size++;
		stack = stack->next;
	}
	return size;
}

int find_index(int *sorted_arr, int size, int value) {
	for (int i = 0; i < size; i++) {
		if (sorted_arr[i] == value) {
			return i;
		}
	}
	return -1;
}

void sort_array(int *arr, int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int find_min(t_stack *stack)
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

int find_max(t_stack *stack)
{
	int max;
	
	if (!stack)
		return (-1);
	t_stack *tmp = stack;
	max = tmp->content;
	//printf("------ Start of fin Max ------\n");
	while (tmp)
	{
		//printf("Cur max: %i - cur: %i\n", max, tmp->content);
		if (max < tmp->content)
		{
			max = tmp->content;
		}
		tmp = tmp->next;
	}
	//printf("Final max: %i\n", max);
	//printf("------ End of fin Max ------\n");
	return max;
}

void replace_with_indices(t_stack **stack_a)
{
	int size = get_stack_size(*stack_a);
	
	int *values = (int *)malloc(size * sizeof(int));
	t_stack *tmp = *stack_a;
	for (int i = 0; i < size; i++) {
		values[i] = tmp->content;
		tmp = tmp->next;
	}
	
	int *sorted_values = (int *)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		sorted_values[i] = values[i];
	}
	sort_array(sorted_values, size);
	
	tmp = *stack_a;
	while (tmp != NULL) {
		tmp->content = find_index(sorted_values, size, tmp->content);
		tmp = tmp->next;
	}
	
	free(values);
	free(sorted_values);
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

void print_stack_big(t_stack *stack, char name) {
	printf("Stack elements %c: ", name);
	while (stack != NULL) {
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int find_max_index(t_stack *stack) {
	int max;
	int max_index = 0;
	int index = 0;

	if (!stack)
		return -1;

	max = stack->content;
	
	while (stack != NULL) {
		if (stack->content > max) {
			max = stack->content;
			max_index = index;
		}
		stack = stack->next;
		index++;
	}
	return max_index;
}

int find_min_index(t_stack *stack) 
{
	int		min;
	int		min_index	= 0;
	int		index 		= 0;

	if (!stack)
		return -1;

	min = stack->content;
	
	while (stack != NULL) {
		if (stack->content < min) {
			min = stack->content;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	
	return min_index;
}