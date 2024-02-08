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

void	last_cmd(int ac, char **av, char **env, t_pipex *data)
{
	data->pid[ac - 3] = fork();
	if (!data->pid[ac - 3])
		process(data->in_fd, data->out_fd, av[ac - 2], env);
	else
	{
		if (close(data->in_fd) < 0 || close(data->out_fd) < 0)
			ft_throw(strerror(errno));
		waitpid(data->pid[ac - 3], NULL, 0);
	}
}

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
		{
			if (close(data->pipe[0]) < 0)
				ft_throw(strerror(errno));
			process(data->in_fd, data->pipe[1], av[i + 1], env);
		}
		else if (close(data->pipe[1]) < 0
			|| dup2(data->pipe[0], data->in_fd) < 0 || close(data->pipe[0]) < 0)
			ft_throw(strerror(errno));
	}
	last_cmd(ac, av, env, data);
	i = 0;
	while (i < ac - 2)
		waitpid(data->pid[i++], NULL, 0);
	free(data->pid);
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
