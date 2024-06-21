#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);
}

int	main(int ac, char **av)
{
	//char	*s1 = "     ";
	char	*s2 = "hello";
	char *s1 = malloc(strlen(s2));

	ft_strcpy(s1, s2);
	// strcpy(s1, s2);
	 printf("s1 : %s", s1);
	 printf("s2 : %s", s2);
	return (0);
}


// typedef	struct	s_list
// {
// 	struct s_list	*next;
// 	void			*data;
// }					t_list;

// int	ft_list_size(t_list *begin_list)
// {
// 	int		i;
// 	t_list	*current = begin_list; // ^= i=0

// 	if(!current)
// 		return (0);
// 	i = 1;
// 	while(current->next)
// 	{
// 		i++;
// 		current = current->next;
// 	}
// 	return(i);
// }

// #include "ft_list.h"

// int	ft_list_size(t_list *begin_list)
// {
// 	if (begin_list == 0)
// 		return (0);
// 	else
// 		return (1 + ft_list_size(begin_list->next));
// }

// #include <unistd.h>
// #include <stdio.h>

// int		ft_strlen(char *s)
// {
// 	int		i;

// 	i = 0;

// 	while(s[i])
// 		i++;

// 	return (i);
// }

// // int		ft_wordlen(char *w)
// // {
// // 	int		i;

// // 	i = 0;

// // 	while(s[i] != ' ' || s[i] != '	')
// // 		i++;

// // 	return (i);
// // }

// // void	ft_putword(char *s)
// // {
// // 	int		i;

// // 	i = 0;

// // 	while(s[i] && s[i] != ' ' && s[i] != '	')
// // 		write(1, &s[i], 1);

// // 	return ();
// // // }

// void	rv(char *s)
// {
// 	int		i;
// 	int		j;
// 	char	c;
	
// 	i = ft_strlen(s);
// 	j = ft_strlen(s);


// 	// on le met au debut pour pas comment sur le char de fin
// 	i--;
// 	j--;
// while(s[i] != 0)
// {
// 	while(s[i] != ' ' && s[i] != '	')
// 	{
// 		i--;
// 		j--;
// 	}

// 	i++;
// 	while(s[i] != ' ' && s[i] != '	')
// 	{
// 		c = s[i];
// 		write(1, &c, 1);
// 		i++;
// 	}

// 	write(1, " ", 1);
// }


// 	if(s[i] == ' ' || s[i] == '	')
// 	// while(s[i] != 0)
// 	{
// 		printf("i : %i\n", i);
// 		// si on est pas a la fin (au debut de s)
// 		// on recule jusquau debut du mot
// 		// printf("i2 : %i\n", i);
		
// 		//ecris un seul mot
// 		while(s[i] != ' ' || s[i] != '	')
// 		{
// 			c = s[i];
// 			printf("%c", c);
// 			i++;
// 			// write(1, &c, 1);
// 		}

// 		// //si s existe toujours, recule jusqua ' '
// 		// if(s[i] != 0)
// 		// 	while(s[i] && (s[i] != ' ' || s[i] != '	'))
// 		// 		i--;

// 		// //si on trouve un espace, on l'imprime
// 		// if(s[i] == ' ')
// 		// 	write(1, " ", 1);

// 		// // on recule pour pas se trouver sur ' '
// 		// i--;
// 	}
// 	return ;
// }
// 	//aller a la fin
// 				// "hello world are you there?\0"
// 				//	01234567890123456789012345 6
// 							  1			2
// 	//boucle										src		dst
// 		//aller au debut du mot 			s		20		0
// 		//ecrire le mot dans le bon sens	s-e		20-25	0-5
// 		//espace											6
// 		//retourner a lemplacement			s		16		7-9

// 		trouver spc - aller au debut du mot
// 		ecrire mot jusqua spc 
// 		compter longueur du mot
// 		index pour dst
// 		index pour src avec b : taille du mot, taille de la str
// 		putchar inverse ?
// 		//


// int		main(int ac, char **av)
// {
// 	if(ac == 2)
// 		rv(av[1]);
	
// 	write(1, "\n", 1);
	
// 	return (0);
// }