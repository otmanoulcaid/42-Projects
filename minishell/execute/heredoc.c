/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:56:24 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/10 14:57:48 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	heredoc(char *del)
{
	int		fd;
	int		fd2;
	char	*line;

	fd2 = open(".tmp", O_WRONLY | O_CREAT, 0644);
	if (fd2 < 0)
		ft_throw("ERROR_OPEN_HERDOC");
	fd = open(".tmp", O_RDONLY);
	if (fd < 0)
		ft_throw("ERROR_OPEN_HERDOC");
	if (unlink(".tmp") < 0)
		ft_throw("ERRON_UNLINK_HERDOC");
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(1);
		if (!line || (!ft_strncmp(line, del, ft_strlen(line) - 1)
				&& ((ft_strlen(line) - 1) == ft_strlen(del))))
			break ;
		write(fd2, line, ft_strlen(line));
		(free(line), line = NULL);
	}
	close(fd2);
	return (fd);
}