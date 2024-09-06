/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:25 by moni              #+#    #+#             */
/*   Updated: 2024/09/06 19:59:59 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack	*new_node(char *av, t_info *info)
{
	t_stack		*new;
	int			number;

	number = ft_atoi(av);
	new = malloc(sizeof(t_stack));
	if(!new)
		return NULL;
	new->content = number;
	info->size++;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push_back(t_stack **stack, t_stack *new)
{
	t_stack *temp;

	if(!new)
		return ;

	if (!*stack)
	{
		*stack = new;
		return ;
	}

	temp = *stack;
	while (temp->next != NULL)
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

void	creat_stack(t_stack **stack_a, t_stack **stack_b, t_info **info, int ac, char **av)
{
	t_stack	*new_number;
	int		i;

	*info = malloc(sizeof(t_info));
	*stack_b = malloc(sizeof(t_stack));
	if (*info == NULL || *stack_b == NULL)
		return ;
	(*info)->move = 0;
	(*info)->size = 0;
	*stack_a = new_node(av[1], *info);
	i = 2;
	while (i < ac)
	{
		new_number = new_node(av[i], *info);
		if (new_number)
			push_back(stack_a, new_number);
		i++;
	}
}