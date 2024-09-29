/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:14:15 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 19:54:02 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_price	*find_best_price(t_stack *a)
{
	t_stack	*cheapest;

	cheapest = a;
	a = a->next;
	while (a)
	{
		if (cheapest->struct_price->price > a->struct_price->price)
			cheapest = a;
		a = a->next;
	}
	return (cheapest->struct_price);
}

void	store_prices(t_stack *a, int stage_a, int stage_b)
{
	if (stage_b > stage_a)
		a->struct_price->price = stage_b;
	else
		a->struct_price->price = stage_a;
	a->struct_price->a_price = stage_a;
	a->struct_price->b_price = stage_b;
}

int	calculate_stage_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		stage_b;
	int		b_max;
	int		b_min;

	stage_b = 1;
	tmp = b;
	b_max = find_max(tmp);
	b_min = find_min(tmp);
	if (a->content > b_max || a->content < b_min)
		stage_b = find_max_index(tmp);
	else
	{
		while (tmp->next && !(a->content < tmp->content && a->content
				> tmp->next->content))
		{
			stage_b++;
			tmp = tmp->next;
		}
	}
	return (stage_b);
}

void	calculate_price(t_stack *a, t_stack *b, t_info *info)
{
	int	stage_a;
	int	stage_b;

	stage_a = 0;
	while (get_stack_size(a) != 0)
	{
		stage_b = calculate_stage_b(a, b);
		store_prices(a, stage_a, stage_b);
		a = a->next;
		stage_a++;
	}
}

void	sort_100_500(t_stack **a, t_stack **b, t_info *info)
{
	t_price	*cheapest;

	pb(a, b, info);
	pb(a, b, info);
	initialize_struct_price(*a);
	while (get_stack_size(*a))
	{
		calculate_price(*a, *b, info);
		cheapest = find_best_price(*a);
		rotate_stack(a, b, info, cheapest);
		pb(a, b, info);
	}
	if (find_max_index(*b) > (get_stack_size(*b) / 2))
	{
		while ((*b)->content != find_max(*b))
			rrb(b, info);
	}
	else
	{
		while ((*b)->content != find_max(*b))
			rb(b, info);
	}
	while (*b)
		pa(a, b, info);
}
