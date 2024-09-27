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
		if(!new)
			return NULL;
		new->content = number;
		info->size++;
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}
	write(2, "Error\n", 6);
	return NULL;
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

/// @brief Creates two stacks and fills stack_a with the input values.
/// @param[in]  stack_a   A pointer to the stack_a to be created and filled.
/// @param[in]  stack_b   A pointer to the stack_b, typically initialized but not filled here.
/// @param[in]  info      Any additional information needed for creating the stack (size, move).
/// @param[in]  ac        The argument count, typically passed from command-line arguments.
/// @param[in]  av        The argument vector, the actual input values passed as strings.
void create_stack(t_stack **stack_a, t_stack **stack_b, t_info **info, int ac, char **av)
{
	t_stack *new_number;
	int i;

	*stack_b = NULL; // Just set *stack_b to NULL, no need to malloc

	*info = malloc(sizeof(t_info));
	if (!*info)
		return;
	(*info)->move = 0;
	(*info)->size = 0;

	*stack_a = new_node(av[0], *info);
	i = 1;
	while (av[i])
	{
		new_number = new_node(av[i], *info);
		if (new_number)
			push_back(stack_a, new_number);
		i++;
	}
}