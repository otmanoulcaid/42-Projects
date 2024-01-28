/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:05:14 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/23 23:05:14 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	multiple_pipes(int ac, char **av, char **env, t_pipex *data)
{
	int		i;

	i = -1;
	while (++i < ac - 3)
	{
		if (pipe(data->pipe) < 0)
			ft_throw(strerror(errno));
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			ft_throw(strerror(errno));
		if (!data->pid[i])
			(close(data->pipe[0]), process(data->in_fd, data->pipe[1],
					av[i + 1], env));
		else
			(close(data->pipe[1]), dup2(data->pipe[0], data->in_fd),
				waitpid(data->pid[i], NULL, 0));
	}
	data->pid[i] = fork();
	if (!data->pid[i])
		process(data->in_fd, data->out_fd, av[i + 1], env);
	else
		(close(data->in_fd), close(data->out_fd),
			waitpid(data->pid[i], NULL, 0));
}

void	process(int input, int output, char *av, char **env)
{
	char	**cmd;

	cmd = get_cmd(av, env);
	if (!cmd)
		ft_throw(strerror(errno));
	if (dup2(input, 0) < 0 || dup2(output, 1) < 0)
		ft_throw(strerror(errno));
	execve(cmd[0], cmd, env);
	ft_throw(strerror(errno));
}
