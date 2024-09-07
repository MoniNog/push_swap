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

void	sort_all(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	min;
	int	a;

	a = 0;
	while (a < info->size)// tant quil reste qqch dans la stack
	{
		min = find_min(*stack_a);
		while ((*stack_a)->content != min)
			ra(stack_a, info);
		if(a < info->size)
			pb(stack_a, stack_b, info);
		(void)info;
		a++;
	}
	// print_stack(*stack_a, *stack_b, info);

	while (*stack_b)
		pa(stack_a, stack_b, info);
}
