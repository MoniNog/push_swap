/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/05/24 12:24:57 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et manipulation des cartes du jeu. */
#include "../includes/so_long.h"
#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
// applique la fonction f au collier 
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	print_content(void *content)
{
	ft_printf("%s", (char *)content);
}

// mettre mon GNL !!!
void	get_map(t_list *map, char *mapname)
{
	int		fd;
	t_list	*ligne;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		ft_printf("error, file can't be open\n");
	ligne = ft_lstnew(get_next_line(fd)); // initialisation 1ere ligne
	while (ligne->content != NULL)
	{
		ft_lstadd_back(&map, ligne); // ajoute ligne a la suite de la carte
		ligne = ft_lstnew(get_next_line(fd)); // lis ligne suivante et je la stocke dans la nouvelle liste (collection de listes)
	}
	ft_lstiter(map, print_content);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*carte;
	s_game	*jeu;

	carte = NULL;
	if (argc == 2)
		get_map(carte, argv[1]);
	return(0);
}