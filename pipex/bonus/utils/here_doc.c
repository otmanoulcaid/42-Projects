/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:12:29 by codespace         #+#    #+#             */
/*   Updated: 2024/02/02 01:05:32 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	pipex(char **av, char **env, t_pipex *data)
{
	int	pid[2];

	if (pipe(data->pipe) < 0)
		ft_throw(strerror(errno));
	pid[0] = fork();
	if (pid[0] == -1)
		ft_throw(strerror(errno));
	if (pid[0])
		(close(data->pipe[0]), process(data->in_fd, data->pipe[1], av[1], env));
	else
		(close(data->pipe[1]), waitpid(pid[0], NULL, 0));
	pid[1] = fork();
	if (pid[1] == -1)
		ft_throw(strerror(errno));
	if (!pid[1])
		process(data->pipe[0], data->out_fd, av[2], env);
	else
		(close(data->pipe[1]), waitpid(pid[1], NULL, 0), close(data->in_fd),
			close(data->pipe[0]), close(data->out_fd));
}

void	here_doc(int ac, char **av, char **env, t_pipex *data)
{
	char	*line;

	data->in_fd = open("here_doc", O_RDWR | O_CREAT | O_APPEND, 0777);
	if (data->in_fd < 0)
		ft_throw(strerror(errno));
	data->out_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	if (data->out_fd < 0)
		ft_throw(strerror(errno));
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line || !ft_strncmp(line, *av, ft_strlen(*av)))
			break ;
		if (write(data->in_fd, line, ft_strlen(line)) < 0)
			ft_throw(strerror(errno));
		(free(line), line = NULL);
	}
	if (line)
		free(line);
	pipex(av, env, data);
}
