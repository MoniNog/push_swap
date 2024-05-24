/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:22:33 by jerdos-s          #+#    #+#             */
/*   Updated: 2024/05/14 11:26:02 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	size_t			over;
	size_t			i;
	unsigned char	*tab;

	over = size * nmemb;
	if (!nmemb || !size)
		return (NULL);
	if (over / nmemb != size)
		return (NULL);
	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	tab = (unsigned char *)res;
	while (i < size * nmemb)
		tab[i++] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, len + 1);
	ft_strlcat(res, s2, len + 1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*current;

	current = (char *)s;
	if (!current)
		return (NULL);
	while (*current != (char)c)
	{
		if (*current == '\0')
			return (NULL);
		current++;
	}
	return (current);
}

char	*ft_substr(char const *s, size_t len)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_get_line(char *buff)
{
	char	*end;
	char	*res;
	size_t	len;

	end = ft_strchr(buff, '\n');
	if (!end)
		end = ft_strchr(buff, '\0');
	if (!end)
		return (end);
	len = end - buff + 1;
	res = ft_ssubstr((char const *)buff, len);
	return (res);
}