/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:15 by moni              #+#    #+#             */
/*   Updated: 2024/09/21 20:22:20 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_3(t_stack **a, t_stack **b, t_info *info)
{
	int		min = find_min(*a);
	int		max = find_max(*a);
	if ((*a)->content == min)
	{
		if ((*a)->next->content < (*a)->next->next->content)// 1 2 3
			return ;
		else// 1 3 2
		{
			rra(a, info);// 1 3 2
			sa(a, info);
			return ;
		}
	}
	else if ((*a)->content == max)// 321 312
	{
		if ((*a)->next->content == min)// 312
		{
			ra(a, info);
			return ;
		}
		else//321
		{
			ra(a, info);
			sa(a, info);
			return ;
		}
	}
	else if ((*a)->next->content == min)// 213
	{
		sa(a, info);
		return ;
	}
	else if ((*a)->next->content != min)// 231
	{
		rra(a, info);
		return;
	}
	else
		return;
}
