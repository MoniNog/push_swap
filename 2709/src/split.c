/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:58:53 by moni              #+#    #+#             */
/*   Updated: 2024/09/14 19:58:06 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

int	count_words(const char *s, char c)
{
	int	n_word;
	int	i;

	n_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n_word++;
		i++;
	}
	return (n_word);
}

char	**split(const char *s, char c)
{
	char	**array;
	int		n_word;
	int		n;
	int		i;
	int		j;

	n_word = 0;
	n = 0;
	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	n_word = count_words(s, c);
	array = malloc(sizeof(char *) * n_word);
	if (!array)
		return (NULL);
	while (n < n_word)
	{
		array[n] = malloc(sizeof(char) * count_len_word(s, c, i) + 1);
		if (!array[n])
			return (NULL);
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != c && s[i])
			array[n][j++] = s[i++];
		array[n][j] = '\0';
		n++;
	}
	array[n] = (NULL);
	return (array);
}

int	ft_iswhitespace(int c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

char	*clean_whitespace(const char *s)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		while (ft_iswhitespace(s[i]) == 1)
			i++;
		while (s[i] && ft_iswhitespace(s[i]) == 0)
			dest[j++] = s[i++];
		if (s[i])
			dest[j++] = ' ';
	}
	dest[j] = '\0';
	return (dest);
}
