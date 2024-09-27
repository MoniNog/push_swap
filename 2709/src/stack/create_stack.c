/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:25 by moni              #+#    #+#             */
/*   Updated: 2024/09/15 18:53:48 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack	*new_node(char *av, t_info *info)
{
	t_stack		*new;
	int			number;

	number = ft_atoi(av);
	if (is_int(number) == true)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (NULL);
		new->content = number;
		info->size++;
		new->next = (NULL);
		new->prev = (NULL);
		return (new);
	}
	write(2, "Error\n", 6);
	return (NULL);
}

void	push_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next != (NULL))
	{
		if (temp->content == new->content)
		{
			free(*stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
}

void	create_stack(t_stack **a, t_stack **b, t_info **info, char **av)
{
	t_stack	*new_number;
	int		i;

	i = 1;
	*b = (NULL);
	*info = malloc(sizeof(t_info));
	if (!*info)
		return ;
	(*info)->move = 0;
	(*info)->size = 0;
	*a = new_node(av[0], *info);
	while (av[i])
	{
		new_number = new_node(av[i], *info);
		if (new_number)
			push_back(a, new_number);
		i++;
	}
}
