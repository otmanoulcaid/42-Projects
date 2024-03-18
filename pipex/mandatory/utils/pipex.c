* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:05:14 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/17 03:51:54 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex(char **av, char **env, t_pipex *data)
{
	data->pid[0] = fork();
	if (data->pid[0] == -1)
		ft_throw(strerror(errno));
	if (!data->pid[0])
	{
		if (close(data->pipe[0]) < 0)
			ft_throw(strerror(errno));
		process(data->fd_in, data->pipe[1], av[1], env);
	}
	else if (close(data->pipe[1]) < 0)
		ft_throw(strerror(errno));
	data->pid[1] = fork();
	if (data->pid[1] == -1)
		ft_throw(strerror(errno));
	if (!data->pid[1])
		process(data->pipe[0], data->fd_out, av[2], env);
	else if (close(data->pipe[0]) < 0 || close(data->fd_in) < 0
		|| close(data->fd_out) < 0)
		ft_throw(strerror(errno));
	waitpid(data->pid[0], NULL, 0);
	waitpid(data->pid[1], NULL, 0);
}

void	process(int input, int output, char *av, char **env)
{
	char	**cmd;

	cmd = get_cmd(av, env);
	if (dup2(input, 0) < 0 || dup2(output, 1) < 0)
		ft_throw(strerror(errno));
	execve(cmd[0], cmd, env);
	ft_throw(strerror(errno));
}
