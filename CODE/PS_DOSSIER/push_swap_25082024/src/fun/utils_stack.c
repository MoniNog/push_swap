/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:49:37 by moni              #+#    #+#             */
/*   Updated: 2024/09/05 21:42:54 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static int	ft_iswhitespace(int c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);// digit
	return (1);//
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		minus;
	long	nb;

	i = 0;
	minus = 1;
	nb = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	if (minus * nb <= INT_MAX && minus * nb >= INT_MIN)
		return (minus * nb);
	else
		ft_putstr_fd("Error\n", 1);
	exit(1);
}

t_stack	*new_node(char *av, t_info *info)
{
	t_stack		*new;
	int			number;

	number = ft_atol(av);
	new = malloc(sizeof(t_stack));
	if(!new)
	{
		return NULL;
	}
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

// t_stack		*pop(t_stack **stack)
// {
// 	t_stack	*tmp;

// 	if(!stack ||!*stack)
// 		return NULL;

	
// 	tmp = *stack;
// 	*stack = (*stack)->next;
// 	if(*stack)
// 		(*stack)->prev = NULL;
	
// 	return (tmp);//on recupere ladresse
// }

// void	push(t_stack **stack, t_stack *new)
// {
// 	if (!new)
// 		return ;
	
// 	new->next = *stack;
// 	if(*stack)
// 		(*stack)->prev = new;

// 	*stack = new;
// }
