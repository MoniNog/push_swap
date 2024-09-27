// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   int*c.c                                            :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2024/08/29 13:18:48 by moni              #+#    #+#             */
// // /*   Updated: 2024/08/31 19:04:54 by moni             ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// #include "../../includes/pushswap.h"

// void	ft_swap(int *a, int *b)
// {
//     int		temp;

//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int		*sort_c(int *c, t_info *info)
// {
//     int		a;
//     int		temp;

//     a = 0;
//     while (a < info->size - 1)
//     {
//         if (c[a] > c[a + 1])
//         {
//             temp = c[a];
//             c[a] = c[a + 1];
//             c[a + 1] = temp;
//             a = -1; // Reset loop to check again from the beginning
//         }
//         a++;
//     }
//     return c;
// }

// int 	*dup_a_to_c(t_stack **a, t_stack **b, t_info *info)
// {
//     int		*c;
//     int		i;
//     int		j;

//     c = malloc(sizeof(int) * info->size);
//     if (!c)
//         return NULL;
//     i = 0;
//     while (*a)
//     {
//         c[i] = (*a)->content;
//         i++;
//         *a = (*a)->next;
//     }

//     sort_c(c, info);
//     j = 0;
//     while (j < info->size)
//     {
//         printf("index - [ %i ] --- content : [ %i ]\n", j, c[j]);
//         pb(a, b, info);//! ne pas enlever !!!
//         j++;
//     }

//     return c;
// }

// void	do_moves_2(t_stack **stack_a, t_stack **stack_b, t_stack *mem)
// {
//     t_stack	*stack = mem; // Utiliser mem au lieu de *stack_b

//     while (stack->rra && stack->rrb)
//     {
//         rrr(stack_a, stack_b, NULL);
//         stack->rra--;
//         stack->rrb--;
//     }
//     while (stack->rra)
//     {
//         rra(stack_a, NULL);
//         stack->rra--;
//     }
//     while (stack->rrb)
//     {
//         rrb(stack_b, NULL);
//         stack->rrb--;
//     }
//     while (stack->rb)
//     {
//         rb(stack_b, NULL);
//         stack->rb--;
//     }
//     pa(stack_a, stack_b, NULL);
// }

// void	do_moves_1(t_stack **stack_a, t_stack **stack_b, t_stack *mem)
// {
//     t_stack	*stack = mem; // Utiliser mem au lieu de *stack_b

//     while (stack->ra && stack->rb)
//     {
//         rr(stack_a, stack_b, NULL);
//         stack->ra--;
//         stack->rb--;
//     }
//     while (stack->ra)
//     {
//         ra(stack_a, NULL);
//         stack->ra--;
//     }
//     while (stack->rb)
//     {
//         rb(stack_b, NULL);
//         stack->rb--;
//     }	
//     while (stack->rrb)
//     {
//         rrb(stack_b, NULL);
//         stack->rrb--;
//     }
//     pa(stack_a, stack_b, NULL);
// }

// void	do_moves(t_stack **stack_a, t_stack **stack_b, t_stack *mem)
// {
//     if (mem->move == 1)
//         do_moves_1(stack_a, stack_b, mem);
//     else if (mem->move == 2)
//         do_moves_2(stack_a, stack_b, mem);
// }

// void	push_one(t_stack **stack_a, t_stack **stack_b, t_info *info)
// {
//     t_stack	*current;
//     t_stack	*mem;
//     int		max_moves;

//     if (!stack_a || !stack_b || !info || !(*stack_b))
//         return;

//     max_moves = INT_MAX;
//     current = *stack_b;
//     mem = NULL;

//     while (current->next != *stack_b)
//     {
//         if (current->sa + current->sb + current->ra + current->rb
//             + current->rra + current->rrb < max_moves)
//         {
//             max_moves = current->sa + current->sb + current->ra
//                 + current->rb + current->rra + current->rrb;
//             mem = current;
//         }
//         current = current->next;
//     }
//     if (current->sa + current->sb + current->ra + current->rb
//         + current->rra + current->rrb < max_moves)
//     {
//         max_moves = current->sa + current->sb + current->ra
//             + current->rb + current->rra + current->rrb;
//         mem = current;
//     }
//     if (mem)
//         do_moves(stack_a, stack_b, mem);
// }

// void	find_best_push(t_stack **stack_a, t_stack **stack_b, t_info *info)
// {
//     t_stack	*b;
//     int		i;
//     int		size;

//     b = *stack_b;
//     i = 0;
//     size = info->size;
//     while (b->next != *stack_b)
//     {
//         if (i <= size / 2)
//             b->rb = i;
//         else
//             b->rrb = size - i;
//         prepare_stack_a(stack_a, &b, info);
//         i++;
//         b = b->next;
//     }
//     if (i <= size / 2)
//         b->rb = i;
//     else
//         b->rrb = size - i;
//     prepare_stack_a(stack_a, &b, info);
//     push_one(stack_a, stack_b, info);
// }

// void	find_spot(t_max **max, int i, t_stack **b, t_stack *a)
// {
//     int	curr_max;

//     if ((*b)->content < a->content)
//     {
//         curr_max = a->index - (*b)->index;
//         if (curr_max < (*max)->nb)
//         {
//             (*max)->nb = curr_max;
//             if (i <= (*max)->size / 2)
//             {
//                 (*b)->move = 1;
//                 (*b)->ra = i;
//             }
//             else
//             {
//                 (*b)->move = 2;
//                 (*b)->rra = (*max)->size - i;
//             }
//         }
//     }
// }

// void	t_max_init(t_max **max, t_stack **stack_a, t_info *info)
// {
//     *max = malloc(sizeof(t_max));
//     (*max)->nb = 2147483647;
//     (*max)->size = stack_size(info); // Passer un pointeur de type t_stack **
// }

// void	find_spot_in_loop(t_stack **stack_a, t_stack **b, t_max **max)
// {
//     t_stack	*a;
//     int		i;

//     a = *stack_a;
//     i = 0;
//     while (a->next != *stack_a)
//     {
//         find_spot(max, i, b, a);
//         a = a->next;
//         i++;
//     }
//     find_spot(max, i, b, a);
// }

// void	markup_init(t_stack **stack_a)
// {
//     t_stack	*stack;

//     stack = *stack_a;
//     while (stack->next != *stack_a)
//     {
//         stack->value = 0;
//         stack = stack->next;
//     }
//     stack->value = 0;
// }

// void	markup(t_stack **stack_a, t_seq *seq)
// {
//     t_stack	*stack;
//     t_stack	*next;
//     int		i;

//     markup_init(stack_a);
//     i = 0;
//     stack = *stack_a;
//     while (i++ < seq->max_index)
//         next = stack->next;
//     stack->value = 1;
//     i = stack->index;
//     next = stack->next;
//     seq->start = stack->index;
//     while (next->next != *stack_a)
//     {
//         if (i == next->index - 1)
//         {
//             next->value = 1;
//             i = next->index;
//         }
//         next = next->next;
//     }
//     if (i == next->index - 1)
//         next->value = 1;
// }

// t_seq	*seq_init(t_seq **seq)
// {
//     (*seq) = malloc(sizeof(t_seq));
//     (*seq)->max_len = 0;
//     (*seq)->curr_len = 1;
//     return (*seq);
// }

// void	create_sequence(t_stack *stack, t_seq **seq, int i)
// {
//     t_stack	*it;
//     int		prev;

//     it = stack->next;
//     prev = stack->index;
//     (*seq)->curr_len = 0;
//     (*seq)->index = i;
//     while (it->next != stack)
//     {
//         if (prev == it->index - 1)
//         {
//             (*seq)->curr_len++;
//             prev = it->index;
//         }
//         it = it->next;
//     }
//     if (prev == it->index - 1)
//         (*seq)->curr_len++;
//     it = it->next;
//     if ((*seq)->curr_len > (*seq)->max_len)
//     {
//         (*seq)->max_len = (*seq)->curr_len;
//         (*seq)->max_index = (*seq)->index;
//     }
// }

// t_seq	*sequence(t_stack **stack)
// {
//     t_seq	*seq;
//     t_stack	*node;
//     int		i;

//     seq = seq_init(&seq);
//     node = *stack;
//     i = 0;
//     while (node->next != *stack)
//     {
//         create_sequence(node, &seq, i);
//         node = node->next;
//         i++;
//     }
//     return (seq);
// }

// int	find_index(t_stack *stack_a, t_stack *b, int max, t_stack *stack)
// {
//     int		index;
//     int		i;

//     i = 0;
//     while (stack->next != stack_a)
//     {
//         if (b->content > stack->content)
//         {
//             if (stack->content > max)
//             {
//                 max = stack->content;
//                 index = i;
//             }
//         }
//         stack = stack->next;
//         i++;
//     }
//     if (b->content > stack->content)
//         if (stack->content > max)
//             index = i;
//     return (index);
// }

// int	is_max(t_stack *stack_a, t_stack *b)
// {
//     t_stack	*stack;
//     int		max;

//     stack = stack_a;
//     while (stack->next != stack_a)
//     {
//         if (stack->content > b->content)
//             return (-1);
//         stack = stack->next;
//     }
//     if (stack->content > b->content)
//         return (-1);
//     stack = stack_a;
//     max = -2147483648;
//     return (find_index(stack_a, b, max, stack));
// }

// void	check_last_index(t_stack **staack, t_stack *stack, t_max *max, int j, t_info *info)
// {
//     if (stack->index == 0)
//     {
//         if (max->nb <= max->size / 2)
//             while (j++ < max->nb)
//                 ra(staack, info);
//         else
//             while (j++ < max->size - max->nb)
//                 rra(staack, info);
//     }
// }

// void	reorder(t_stack **stack, int size, int index, t_info *info)
// {
//     t_stack	*current;
//     int		i;
//     int		j;

//     current = *stack;
//     i = 0;
//     j = 0;
//     while (current->next != *stack)
//     {
//         if (current->index == index)
//         {
//             if (i <= size / 2)
//                 while (j++ < i)
//                     ra(stack, info);
//             else
//                 while (j++ < size - i)
//                     rra(stack, info);
//             return ;
//         }
//         i++;
//         current = current->next;
//     }
//     check_last_index(stack, current, &((t_max){i, size}), j, info);
// }

// void	check_sa_needed(t_stack **stack, t_seq **seq)
// {
//     t_seq	*fake_seq;

//     sa(stack, 0);
//     fake_seq = sequence(stack);
//     if (fake_seq->max_len > (*seq)->max_len)
//     {
//         write(1, "sa\n", 3);
//         markup(stack, fake_seq);
//         free(*seq);
//         *seq = fake_seq;
//     }
//     else
//     {
//         free(fake_seq);
//         sa(stack, 0);
//     }
// }

// void	big_sort(t_stack **stack_a, t_stack **stack_b, t_info *info)
// {
//     t_seq	*seq;
//     int		i;
//     int		size;

//     seq = sequence(stack_a);
//     markup(stack_a, seq);
//     check_sa_needed(stack_a, &seq);
//     free(seq);
//     i = 0;
//     size = info->size;
//     while (i <= size)
//     {
//         if (!((*stack_a)->value))
//             pb(stack_a, stack_b, info);
//         else
//             ra(stack_a, info);
//         i++;
//     }
//     while (*stack_b)
//     {
//         moves_init(stack_b, 0);
//         find_best_push(stack_a, stack_b, info);
//     }
//     reorder(stack_a, size, 0, info);
// }

// void	prepare_stack_a(t_stack **stack_a, t_stack **b, t_info *info)
// {
//     t_max	*max;
//     int		i;

//     t_max_init(&max, stack_a, info);
//     i = is_max(*stack_a, (*b));
//     if (i <= max->size / 2 && i >= 0)
//     {
//         (*b)->move = 1;
//         (*b)->ra = i + 1;
//         free(max);
//         return ;
//     }
//     else if (i > max->size / 2 && i >= 0)
//     {
//         (*b)->move = 2;
//         (*b)->rra = max->size - i - 1;
//         free(max);
//         return ;
//     }
//     find_spot_in_loop(stack_a, b, &max);
//     free(max);
// }

// int stack_size(t_info *info)
// {
//     return info->size;
// }

// void	moves_init(t_stack **stack_b, int value)
// {
//     t_stack	*current;

//     current = *stack_b;
//     while (current->next != *stack_b)
//     {
//         current->ra = value;
//         current->rb = value;
//         current->rra = value;
//         current->rrb = value;
//         current = current->next;
//     }
//     current->ra = value;
//     current->rb = value;
//     current->rra = value;
//     current->rrb = value;
// }