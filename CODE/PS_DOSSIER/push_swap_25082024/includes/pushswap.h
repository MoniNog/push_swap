/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:16 by moni              #+#    #+#             */
/*   Updated: 2024/09/01 22:44:23 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;//index max
}					t_stack;

typedef struct s_info
{
	int				size;//nombre de node dans la stack
	int				move;
}					t_info;

void	free_stack(t_stack *stack);
t_stack	*new_node(char *av, t_info *info);
void	push(t_stack **stack_a, t_stack *new);
void	push_back(t_stack **stack_a, t_stack *new);
t_stack		*pop(t_stack **stack);

void		ppush(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, t_info *count);
void	pb(t_stack **a, t_stack **b, t_info *count);

void	swap(t_stack **stack);
void	sa(t_stack **stack_a, t_info *count);
void	sb(t_stack **stack_b, t_info *count);
void	ss(t_stack **stack_a, t_stack **stack_b, t_info *count);

void	rotate(t_stack**stack);
void	rb(t_stack **stack_b, t_info *count);
void	ra(t_stack **stack_a, t_info *count);

void	reverse_rotate(t_stack**stack);
void	rra(t_stack **stack_a, t_info *count);
void	rrb(t_stack **stack_b, t_info *count);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_info *count);

void	tri(t_stack **stack_a, t_stack **stack_b, t_info *info);
void	print_stack(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	creat_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av);
int		stack_size(t_stack **stack);
int		index_of_number_on_stack(t_stack **stack, t_stack *number);
// void	print_c(int *c);
int		*dup_a_to_c(t_stack **stack, t_info *info);

#endif
