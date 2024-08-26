/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:16 by moni              #+#    #+#             */
/*   Updated: 2024/08/26 12:51:36 by moni             ###   ########.fr       */
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
}					t_stack;

void	free_stack(t_stack *stack);
t_stack	*new_node(char *av);
void	push(t_stack **stack_a, t_stack *new);
void	push_back(t_stack **stack_a, t_stack *new);
t_stack		*pop(t_stack **stack);
void		ppush(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack**stack);//rotation
void	rb(t_stack **stack_b);//rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
void	ra(t_stack **stack_a);//ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
void	rr(t_stack **stack_a, t_stack **stack_b);//rr : ra et rb en même temps
void	reverse_rotate(t_stack**stack);
void	rra(t_stack **stack_a);//ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
void	rrb(t_stack **stack_b);//rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
void	rrr(t_stack **stack_a, t_stack **stack_b);//rr : ra et rb en même temps.



#endif
