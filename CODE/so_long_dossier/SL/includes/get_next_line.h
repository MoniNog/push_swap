/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:28:18 by jerdos-s          #+#    #+#             */
/*   Updated: 2024/05/13 15:58:37 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_read_from_buff(char **current_buff, int fd);
char	*ft_get_line(char *current_buff);
char	*ft_init_new_buff(char *current_buff);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_ssubstr(char const *s, size_t len);
size_t	ft_strlen(char const *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif