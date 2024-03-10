/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:32:32 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/10 14:56:39 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	first_process(t_shell *data, t_tokens *token)
{
	if (data->number_of_commands > 1)
	{
		data->pipes[0] = malloc(sizeof(int) * 2);
		if (!data->pipes[0])
			ft_throw("ERROR_MALLOC_PIPE_EXECUTE");
		if (pipe(data->pipes[0]) < 0)
			ft_throw("ERROR_CREAT_PIPE_EXECUTE");
	}
	data->pids[0] = fork();
	if (data->pids[0] < 0)
		ft_throw("ERROR_FORK_MIDDLE_COMMAND");
	if (!data->pids[0])
	{
		if (data->number_of_commands > 1)
		{
			close(data->pipes[0][0]);
			process(data, token, STDIN_FILENO, data->pipes[0][1]);
		}
		else
			process(data, token, STDIN_FILENO, STDOUT_FILENO);
	}
	else if (data->pids[0] && data->number_of_commands > 1)
		close(data->pipes[0][1]);
	waitpid(data->pids[0], &(data->status), 0),
	data->status = WEXITSTATUS(data->status);
}

void	last_process(t_shell *data, t_tokens *token)
{
	int	i;

	i = data->number_of_commands;
	data->pids[i - 1] = fork();
	if (data->pids[i - 1] < 0)
		ft_throw("ERROR_FORK_LAST_COMMAND");
	if (!data->pids[i - 1])
		(process(data, token,
				data->pipes[i - 2][0], STDOUT_FILENO));
	else
		close(data->pipes[i - 2][0]);
}

void	middle_process(t_shell *data, t_tokens *token)
{
	int	i;

	i = 0;
	while (++i < data->number_of_commands - 1)
	{
		data->pipes[i] = malloc(sizeof(int) * 2);
		if (!data->pipes[i])
			ft_throw("ERROR_MALLOC_PIPE_EXECUTE");
		if (pipe(data->pipes[i]) < 0)
			ft_throw("ERROR_CREAT_PIPE_EXECUTE");
		data->pids[i] = fork();
		if (data->pids[i] < 0)
			ft_throw("ERROR_FORK_MIDDLE_COMMAND");
		if (!data->pids[i])
		{
			close(data->pipes[i][0]);
			process(data, token, data->pipes[i - 1][0], data->pipes[i][1]);
		}
		else
			(close(data->pipes[i][1]), close(data->pipes[i - 1][0]),
				token = token->left);
	}
	last_process(data, token);
}

void	execute(t_shell *data)
{
	int			status;
	int			i;

	data->pids = malloc(sizeof(int) * data->number_of_commands);
	if (!data->pids)
		ft_throw("ERROR_MALLOC_PIDS_EXECUTE");
	if (data->number_of_commands == 1)
		return (first_process(data, data->token));
	data->pipes = malloc(sizeof(int *) * (data->number_of_commands - 1));
	if (!data->pipes)
		ft_throw("ERROR_MALLOC_PIPES_EXECUTE");
	first_process(data, data->token);
	middle_process(data, data->token->left);
	i = -1;
	while (++i < data->number_of_commands)
	{
		waitpid(data->pids[i], &status, 0);
		if (WIFEXITED(status))
			data->status = WEXITSTATUS(status);
	}
}
