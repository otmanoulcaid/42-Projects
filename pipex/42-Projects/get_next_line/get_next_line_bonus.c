/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:47:36 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/20 16:49:20 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*tmp;
	int			check;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buffer[fd], 0) < 0 
		|| BUFFER_SIZE < 1)
	{
		if (buffer[fd])
			free(buffer[fd]);
		return (NULL);
	}
	if (buffer[fd] && buffer[fd][0] && exist(buffer[fd]))
		return (ft_gl(buffer + fd));
	while (read_swap(buffer + fd, fd, &check) > 0 && !exist(buffer[fd]))
		check++;
	if (buffer[fd] && buffer[fd][0] && exist(buffer[fd]))
		return (ft_gl(buffer + fd));
	if (buffer[fd] && buffer[fd][0])
	{
		tmp = strjoin("", "");
		change(&tmp, buffer + fd);
		return (tmp);
	}
	free(buffer[fd]);
	return (NULL);
}

int	read_swap(char **buf, int fd, int *check)
{
	char	*tmp;
	char	*ptr;

	*check = 0;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (*check);
	*check = read(fd, tmp, BUFFER_SIZE);
	if (*check <= 0)
	{
		free(tmp);
		return (*check);
	}
	*(tmp + *check) = '\0';
	ptr = strjoin(*buf, tmp);
	if (!ptr)
	{
		free(tmp);
		*check = 0;
		return (*check);
	}
	free(*buf);
	free(tmp);
	*buf = ptr;
	return (*check);
}

char	*strjoin(char *s1, char *s2)
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

char	*ft_gl(char	**buf)
{
	int		l;
	char	*ret;
	char	*tmp;

	l = get_index(*buf);
	ret = malloc(l + 2);
	if (!ret)
		return (NULL);
	ft_cpy(ret, *buf, l + 1);
	ret[l + 1] = '\0';
	tmp = strjoin(*buf + l + 1, "");
	if (!tmp)
	{
		free(ret);
		return (NULL);
	}
	free(*buf);
	*buf = tmp;
	return (ret);
}

void	change(char **s1, char **s2)
{
	char	*help;

	help = *s1;
	*s1 = *s2;
	*s2 = help;
}
