/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:58:53 by moni              #+#    #+#             */
/*   Updated: 2024/09/12 15:08:00 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	count_len_word(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
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
		if (s[i] != c && (i == 0 || s[i - 1] == c))
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

		array[n] = malloc(sizeof(char) * count_len_word(s, c, i) + 1);
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
		array[n][j] = '\0';
		n++;
	}
	array[n] = NULL;
	return (array);
}

int	ft_iswhitespace(int c)
{
	if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
			|| c == '\f'))
		return (0);//pas un whitespace
	return (1);//whitespace
}

char *clean_whitespace(const char *s)
{
	int		i;
	int		j;
	char 	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (strlen(s) + 1)); // Allocate memory for the destination string
	if (!dest)
		return NULL;
	while (s[i])
	{
		while (ft_iswhitespace(s[i]) == 1)
			i++;
		while(s[i] && ft_iswhitespace(s[i]) == 0)
		{
			dest[j] = s[i];
			i++;
			j++;
		}
		if (s[i])
		{
			dest[j] = ' ';
			j++;
		}
	}
	dest[j] = '\0'; // Add null terminator to the destination string
	return(dest);
}

// int main(int ac, char **av)
// {
// 	char *s;

// 	s = "hello world are you there ?";

// 	char **result = split(clean_whitespace(s), ' ');
// 	if (result)
// 	{
// 		int i = 0;
// 		while (result[i])
// 		{
// 			printf("%s\n", result[i]);
// 			i++;
// 		}
// 		// Free the memory allocated for the array
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Error: Failed to split the string.\n");
// 	}

// 	return 0;
// }




// int main(int ac, char **av)
// {
// 	char c;
// 	char *s;

// 	s = "hello world are you there ?";
// 	c = ' ';

// 	char **result = split(s, c);
// 	if (result)
// 	{
// 		int i = 0;
// 		while (result[i])
// 		{
// 			printf("%s\n", result[i]);
// 			i++;
// 		}
// 		// Free the memory allocated for the array
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Error: Failed to split the string.\n");
// 	}

// 	return 0;
// }