// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   int*c.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/29 13:18:48 by moni              #+#    #+#             */
// /*   Updated: 2024/08/31 19:04:54 by moni             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../includes/pushswap.h"

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int 	*dup_a_to_c(t_stack **stack, t_info *info)
{
	int		*c;
	int		i;
	int		j;

	c = malloc(sizeof(int) * info->size);
	if (!c)
		return NULL;
	i = 0;
	while (*stack)
	{
		c[i] = (*stack)->content;
		i++;
		*stack = (*stack)->next;
	}

	j = 0;
	while (j < info->size)
	{
		printf("index - [ %i ] --- content : [ %i ]\n", j, c[j]);
		j++;
	}

	return c;
}

int		*sort_c(int *c, t_info *info)
{
	int		a;
	int		temp;

	a = 0;
	while (a < info->size - 1)
	{
		if (c[a] > c[a + 1])
		{
			temp = c[a];
			c[a] = c[a + 1];
			c[a + 1] = temp;
			a = -1; // Reset loop to check again from the beginning
		}
		a++;
	}
	return c;
}

int	cost_to_bring_up(t_stack **stack, t_stack *current, t_info *price)
{
	int	price;
	price = 0;
	si je suis dans la partie haute
	while (stack)
	{
		if ((stack_size(stack) - index_of_number_on_stack(stack, current)) - (stack_size(stack) / 2))
			price->rrb++;
		if ((stack_size(stack) - index_of_number_on_stack(stack, current)) > (stack_size(stack) / 2))
			price->rb++;
		stack = (*stack)->next;
	}
	return (price);
}

int index_of_number_on_stack(t_stack **stack, t_stack *number)
{
	int			count;
	t_stack		*current;
	count = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current == number)
			return (count);
		count++;
		current = current->next;
	}
	return (-1);
}
price to place in stack b

id price_to_b_placement(t_stack **stack, t_stack *current, t_info *price)
{
	int		price;
	int		index;
	int		size;
	int		*stack_c;
	int		*sorted_c;

	size = stack_size(stack);
	stack_c = dup_a_to_c(stack, price);
	sorted_c = sort_c(stack_c, price);
	index = index_of_number_on_stack(stack, current);
	price->rb = index;
	price->rrb = size - index;
	price->ra = index;
	price->rra = size - index;
	price->move = 0;
	price->min_index = 0;
	price->size = size;
	price->move = price->rb;
	if (price->move > price->rrb)
		price->move = price->rrb;
	if (price->move > price->ra)
		price->move = price->ra;
	if (price->move > price->rra)
		price->move = price->rra;
}
{
	pb(a, b, info);
	pb(a, b, info);
	if (stack_b->content < stack_b->next->content)
		sb(b, info);
	
}	