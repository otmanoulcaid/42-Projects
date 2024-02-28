/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:33:41 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/28 13:20:25 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1)
		j = ft_strlen(s2);
	else
		j = ft_strlen(s2) + ft_strlen(s1);
	result = (char *)malloc(j + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (s1)
	{
		j = 0;
		while (*(s1 + i))
			result[i++] = s1[j++];
	}
	j = 0;
	while (*(s2 + j))
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

int	read_swap(char **buf, int fd)
{
	char	*tmp;
	char	*str;
	int		check;

	check = 0;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		ft_throw("malloc gnl");
	check = read(fd, tmp, BUFFER_SIZE);
	if (check <= 0)
		return (free(tmp), check);
	*(tmp + check) = '\0';
	str = strjoin(*buf, tmp);
	if (!str)
		(free(tmp), ft_throw("join gnl"));
	if (buf)
		(free(*buf), *buf = NULL);
	return (free(tmp), *buf = str, check);
}

char	**get_lines(int fd, int *height)
{
	char	*buffer;
	char	**lines;

	buffer = NULL;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (read_swap(&buffer, fd) > 0)
		;
	lines = ft_split(buffer, '\n', height);
	if (!lines)
		(free(buffer), ft_throw("error getting data from file"));
	return (free(buffer), buffer = NULL, lines);
}
