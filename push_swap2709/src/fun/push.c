/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:53:45 by moni              #+#    #+#             */
/*   Updated: 2024/09/18 19:16:57 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack		*node_to_push;

	if (*src == NULL)//				si la pile source est vide -> EXIT
		{
			printf("empty");
			return;
		}
	
	node_to_push = *src;//			node_to_push pointe sur le debut de la pile source
	*src = (*src)->next;//			MAJ du debut de la pile source : le debut commence apres l'element retire
	if (*src)//						s'il existe toujours une pile apre le retrait du premier element,
		(*src)->prev = NULL;//		le ptr du nouveau premier de la pile source qui pointe sur le precedent devient NULL
	node_to_push->prev = NULL;//	efface le prev de l'element deplace
	
	if (*dest == NULL)//			si la pile dest est vide,
	{
		*dest = node_to_push;//				le nouveau noeud devient le premier de la pile dest
		node_to_push->next = NULL;//		il ny a rien ensuite
	}
	
	else
	{
		node_to_push->next = *dest;//				l'element ajoute pointe sur lancien premier element de la pile dest
		node_to_push->next->prev = node_to_push;//	le prev de lancien premier pointe sur lelement
		*dest = node_to_push;//						MAJ du ptr de la pile dest sur le nouveau premier element
	}
}

void	pa(t_stack **a, t_stack **b, t_info *info)
{
	push(a, b);
	write(1, "pa\n", 3);
	info->move++;
}

void	pb(t_stack **a, t_stack **b, t_info *info)
{
	push(b, a);
	write(1, "pb\n", 3);
	info->move++;
}
