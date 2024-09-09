/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:20:49 by moni              #+#    #+#             */
/*   Updated: 2024/09/09 13:48:04 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


void sort_4(t_stack **a, t_stack **b, t_info *info)
{
	find_min(*a, info);
	if (info->min_index == 0)
	{
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 2)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 3)
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
	find_min(*a, info);
	if (info->min_index == 0)
	{
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 2)
	{
		ra(a, info);
		ra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 3)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 4)
	{
		rra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return;
	}
}

void sort_n(t_stack **a, t_stack **b, t_info *info)
{
	if (info->size <= 1)
		return;

	find_min(*a, info);
	if (info->min_index < info->size / 2)
	{
		int i = 0;
		while (i < info->min_index)
		{
			ra(a, info);
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < info->size - info->min_index)
		{
			rra(a, info);
			i++;
		}
	}

	if (is_sorted(*a) == false)
	{
		pb(a, b, info);
		info->size--;
		sort_n(a, b, info);
		info->size++;
		pa(a, b, info);
	}
}