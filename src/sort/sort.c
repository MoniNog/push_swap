// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   algo.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/27 14:44:28 by moni              #+#    #+#             */
// /*   Updated: 2024/09/02 16:11:40 by moni             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../includes/pushswap.h"

// 1er algo qui est fonctionnel mais pas efficient.
void	sort_all(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	min;
	int	a;

	a = 0;
	while (a < info->size)// tant quil reste qqch dans la stack
	{
		min = find_min(*stack_a, info);
		while ((*stack_a)->content != min)
			ra(stack_a, info);
		if(a < info->size)
			pb(stack_a, stack_b, info);
		(void)info;
		a++;
	}
	while (*stack_b)
		pa(stack_a, stack_b, info);
}

void	sort_2(t_stack **a, t_info *info)
{
	if ((*a)->content > (*a)->next->content)
		sa(a, info);
	else
		return ;
}

void	choose_sort(t_stack **a, t_stack **b, t_info *info)
{
	if (info->size == 2)
	{
		sort_2(a, info);
		return ;
	}
	if (info->size == 3)
	{
		sort_3(a, b, info);
		return ;
	}
	else if (info->size == 4)
	{
		sort_4(a, b, info);
		return ;
	}
	else if (info->size == 5)
	{	
		sort_5(a, b, info);
		return ;
	}
	else
	{
		sort_n(a, b, info);
		return ;
	}
}