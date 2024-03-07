/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:32:32 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/07 17:27:17 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	first_process(t_shell *data, t_tokens *token)
{
	data->pipes[0] = malloc(sizeof(int) * 2);
	if (!data->pipes[0])
		ft_throw("ERROR_MALLOC_PIPE_EXECUTE");
	if (pipe(data->pipes[0]) < 0)
		ft_throw("ERROR_CREAT_PIPE_EXECUTE");
	data->pids[0] = fork();
	if (data->pids[0] < 0)
		ft_throw("ERROR_FORK_MIDDLE_COMMAND");
	if (!data->pids[0])
	{
		close(data->pipes[0][0]);
		process(data, token, STDIN_FILENO, data->pipes[0][1]);
	}
	else
		close(data->pipes[0][1]);
}

void	middle_process(t_shell *data, t_tokens *token)
{
	int	i;
	
	i = 0;
	while (++i < data->number_of_commands - 2)
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
			(close(data->pipes[i][1]),
				process(data, token, data->pipes[i - 1][0],
					data->pipes[i][1]));
		else
			(dup2(data->pipes[i - 1][0], data->pipes[i][1]),
				close(data->pipes[i][1]));
		token = token->left;
	}
}

void	last_process(t_shell *data, t_tokens *token)
{
	data->pids[data->number_of_commands - 1] = fork();
	if (data->pids[data->number_of_commands - 1] < 0)
		ft_throw("ERROR_FORK_MIDDLE_COMMAND");
	if (!data->pids[0])
		process(data, token,data->pipes[0][1], STDOUT_FILENO);
}

void	execute(t_shell *data)
{
	t_tokens	*token;
	int			status;
	int			i;

	data->pipes = malloc(sizeof(int *) * (data->number_of_commands - 1));
	if (!data->pipes)
		ft_throw("ERROR_MALLOC_PIPES_EXECUTE");
	data->pids = malloc(sizeof(int) * data->number_of_commands);
	if (!data->pids)
		ft_throw("ERROR_MALLOC_PIDS_EXECUTE");
	token = data->token;
	first_process(data, token);
	middle_process(data, token);
	last_process(data, token);
	i = -1;
	while (++i < data->number_of_commands)
		waitpid(data->pids[i], &status, 0);
	data->status = status;
}
