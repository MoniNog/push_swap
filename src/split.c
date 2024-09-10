/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:58:53 by moni              #+#    #+#             */
/*   Updated: 2024/09/10 21:02:54 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/pushswap.h"
#include <stdio.h>
#include <stdlib.h>

int	count_len_word(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

/// @brief 
/// @param s string a decouper
/// @param c char qui dit ou decouper
/// @return tableau qui contient les differents mots qu'on vient de decouper
char	**split(const char *s, char c)
{
	char	**array;
	int		n_word;
	int		i;
	int		j;

	if (!s || !c)
		return NULL;
	
	n_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			if (i != 0 && s[i - 1] != c)//dernier char different de ESP
				n_word++;
		i++;
	}
	if (n_word != 0 && s[i - 1] != c) // "alo?" "oups "
	 	n_word++;

	
	array = malloc(sizeof(char*) * n_word);
	if (!array)
		return NULL;
		

    int		n;
	i = 0;
	n = 0;
	
	while (n < n_word)	
	{

		array[n] = malloc(sizeof(char) * count_len_word(s, c, i));
		if (!array[n])
			return NULL;
		
		while (s[i] == c)
			i++;

		j = 0;
		while (s[i] != c && s[i])
		{
			array[n][j] = s[i];
			i++;
			j++;
		}
		n++;
	}

	return (array);
}


int main(int ac, char **av)
{
	char c;
	char *s;

	s = "hello world are you there ?";
	c = ' ';

	char **result = split(s, c);
	if (result)
	{
		int i = 0;
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
		// Free the memory allocated for the array
		free(result);
	}
	else
	{
		printf("Error: Failed to split the string.\n");
	}

	return 0;
}