/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:20:49 by moni              #+#    #+#             */
/*   Updated: 2024/09/21 18:56:24 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


void sort_4(t_stack **a, t_stack **b, t_info *info)
{
	(*a)->min_index = find_min_index(*a);
	// printf("Min pos:  %i", (*a)->min_index);
	if ((*a)->min_index == 0)
	{
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 2)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 3)
	{
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
}

void sort_5(t_stack **a, t_stack **b, t_info *info)
{
	(*a)->min_index = find_min_index(*a);
	if ((*a)->min_index == 0)
	{
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 2)
	{
		ra(a, info);
		ra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 3)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if ((*a)->min_index == 4)
	{
		rra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
}

// void sort_n(t_stack **a, t_stack **b, t_info *info)
// {
// 	if (info->size <= 1)
// 		return;

// 	(*a)->min_index = find_min_index(*a);
// 	int half_size = info->size / 2;
// 	if ((*a)->min_index < half_size)
// 	{
// 		int i = 0;
// 		print_stack(*a, *b, info);
// 		printf("half : %i, %i, %i, %i\n", i, info->size, (*a)->min_index, half_size);
// 		while (i < (*a)->min_index)
// 		{
// 			printf("i: %i, (*a)->min_index : %i\n\n", i, (*a)->min_index);
// 			ra(a, info);
// 			printf("i: %i, (*a)->min_index : %i\n\n", i, (*a)->min_index);
// 			i++;
// 		}
// 		print_stack(*a, *b, info);
// 	}
// 	else
// 	{
// 		int i = 0;
// 		int diff = (info->size - (*a)->min_index);
// 		print_stack(*a, *b, info);
// 		printf("%i, %i, %i, %i\n", i, info->size, (*a)->min_index, diff);
// 		while (i < diff)
// 		{
// 			rra(a, info);
// 			i++;
// 		}
// 	}

// 	if (is_sorted(*a) == false)
// 	{
// 		pb(a, b, info);
// 		info->size--;
// 		sort_n(a, b, info);
// 		pa(a, b, info);
// 		info->size++;
// 	}

// 	print_stack_big(*a, 'a');
// 	print_stack_big(*b, 'b');
// }