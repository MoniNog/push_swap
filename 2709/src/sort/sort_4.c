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

void	min_index_2_or_3(t_stack **a, t_stack **b, t_info *info)
{
	(*a)->min_index = find_min_index(*a);
	if ((*a)->min_index == 2)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return ;
	}
	else if ((*a)->min_index == 3)
	{
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return ;
	}
}

void	sort_4(t_stack **a, t_stack **b, t_info *info)
{
	(*a)->min_index = find_min_index(*a);
	if ((*a)->min_index == 0)
	{
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return ;
	}
	else if ((*a)->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return ;
	}
	else
		min_index_2_or_3(a, b, info);
	return ;
}

void	min_index_3_4_or_5(t_stack **a, t_stack **b, t_info *info)
{
	(*a)->min_index = find_min_index(*a);
	if ((*a)->min_index == 2)
	{
		ra(a, info);
		ra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
	}
	else if ((*a)->min_index == 3)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
	}
	else if ((*a)->min_index == 4)
	{
		rra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
	}
	return ;
}

void	sort_5(t_stack **a, t_stack **b, t_info *info)
{
	(*a)->min_index = find_min_index(*a);
	if ((*a)->min_index == 0)
	{
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return ;
	}
	else if ((*a)->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_4(a, b, info);
		pa(a, b, info);
		return ;
	}
	min_index_3_4_or_5(a, b, info);
}
