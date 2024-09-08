/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:16 by moni              #+#    #+#             */
/*   Updated: 2024/09/08 20:46:12 by moni             ###   ########.fr       */
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

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_info
{
	int				size;
	int				move;
	int				min_index;
}					t_info;

// typedef struct s_sort_4// on process
// {
// 	int				permutation[4];
// 	char			*op;
// }					t_sort_4;

// t_sort_case sort_cases[24] = 
// {
//     {{4, 3, 2, 1}, "sa ra ra sa"},
//     {{4, 3, 1, 2}, "sa ra ra"},
//     {{4, 2, 3, 1}, "rra sa ra"},
//     {{4, 2, 1, 3}, "ra sa"},
//     {{4, 1, 3, 2}, "ra ra sa rra"},
//     {{4, 1, 2, 3}, "ra"},
//     {{3, 4, 2, 1}, "ra ra sa"},
//     {{3, 4, 1, 2}, "ra ra"},
//     {{3, 2, 4, 1}, "sa rra"},
//     {{3, 2, 1, 4}, "ra sa"},
//     {{3, 1, 4, 2}, "ra sa ra"},
//     {{3, 1, 2, 4}, "rra sa ra ra"},
//     {{2, 4, 3, 1}, "ra sa ra ra"},
//     {{2, 4, 1, 3}, "rra sa rra"},
//     {{2, 3, 4, 1}, "rra"},
//     {{2, 3, 1, 4}, "ra ra sa ra"},
//     {{2, 1, 4, 3}, "pb pb ss pa pa"},
//     {{2, 1, 3, 4}, "sa"},
//     {{1, 4, 3, 2}, "ra sa rra rra sa"},
//     {{1, 4, 2, 3}, "sa ra"},
//     {{1, 3, 4, 2}, "rra sa"},
//     {{1, 3, 2, 4}, "ra sa rra"},
//     {{1, 2, 4, 3}, "ra ra sa rra rra"},
//     {{1, 2, 3, 4}, ""}
// };

//	FUN
//	FUN > PUSH
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, t_info *info);
void	pb(t_stack **a, t_stack **b, t_info *info);

//	FUN > SWAP
void	swap(t_stack **stack);
void	sa(t_stack **stack_a, t_info *info);
void	sb(t_stack **stack_b, t_info *info);
void	ss(t_stack **stack_a, t_stack **stack_b, t_info *info);

//	FUN > ROTATE
void	rotate(t_stack **stack);// Rot vers le haut
void	rb(t_stack **stack_b, t_info *info);
void	ra(t_stack **stack_a, t_info *info);

//	FUN > REVERSE ROTATE
void	reverse_rotate(t_stack **stack);// Rot vers le bas
void	rra(t_stack **stack_a, t_info *info);
void	rrb(t_stack **stack_b, t_info *info);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_info *info);


// SORT
// SORT > ALGO
void	sort_all(t_stack **stack_a, t_stack **stack_b, t_info *info);

// SORT > SORT 3
void	sort_3(t_stack **a, t_stack **b, t_info *info);

// SORT > SORT 4
void sort_4(t_stack **a, t_stack **b, t_info *info);
void sort_5(t_stack **a, t_stack **b, t_info *info);
void sort_n(t_stack **a, t_stack **b, t_info *info);

// void	execute_operations(char *operations);
// void	sort_permutation(int stack[4]);

// SORT > UTILS SORT
// int		*dup_a_to_c(t_stack **stack, t_info *info); // on process
// int		index_of_number_on_stack(t_stack **stack, t_stack *number);// on process


// STACK
// STACK > CREAT STACK
t_stack	*new_node(char *av, t_info *info);
void	push_back(t_stack **stack_a, t_stack *new);
void	create_stack(t_stack **stack_a, t_stack **stack_b, t_info** info, int ac, char **av);
long	ft_atol(const char *str);

// STACK > PRINT STACK
void	print_stack(t_stack *stack_a, t_stack *stack_b, t_info *info);
void	print_move_and_size(t_stack *stack_a, t_stack *stack_b, t_info *info);

// STACK > UTILS STACK
int		find_min(t_stack *stack, t_info *info);
int		find_max(t_stack *stack);
int		stack_size(t_stack **stack);
// t_stack	*pop(t_stack **stack);// not used but usefull for lib
// void	push(t_stack **stack_a, t_stack *new);// not used but usefull for lib


// MEMORY MANAGEMENT
void	free_stack(t_stack *stack);

#endif
