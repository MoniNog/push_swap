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

void	begin_3(t_stack **a, t_stack **b, t_info *info)
{
	int		min;

	min = find_min(*a);
	if ((*a)->next->content == min)
	{
		ra(a, info);
		return ;
	}
	else
	{
		ra(a, info);
		sa(a, info);
		return ;
	}
}

void	sort_3(t_stack **a, t_stack **b, t_info *info)
{
	int		min;
	int		max;

	min = find_min(*a);
	max = find_max(*a);
	if ((*a)->content == min)
	{
		if ((*a)->next->content < (*a)->next->next->content)
			return ;
		else
		{
			rra(a, info);
			sa(a, info);
			return ;
		}
	}
	else if ((*a)->content == max)
		begin_3(a, b, info);
	else if ((*a)->next->content == min)
		sa(a, info);
	else if ((*a)->next->content != min)
		rra(a, info);
	return ;
}
