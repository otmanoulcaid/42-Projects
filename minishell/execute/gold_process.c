/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:56 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/09 21:03:32 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	char	**get_args(t_tokens *token, int nbr_arg)
{
	char	**args;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * (nbr_arg + 1));
	if (!args)
		ft_throw("ERROR_MALLOC_GET_ARGS");
	while (token && token->string[0] != '|')
	{
		if (token->class == WORD)
		{
			args[i] = ft_strdup(token->string);
			if (!args[i++])
				ft_throw("ERROR_STRDUP_GET_ARGS");
		}
		else if (token->class != PIPE && token->right->string[0] != '|')
			token = token->right;
		token = token->right;
	}
	args[i] = NULL;
	return (args);
}

static	void	ft_execve(t_shell *data, char **cmd_arg, int input, int output)
{
	char	*abs_path;

	abs_path = absolute_path(cmd_arg[0], data->env);
	if (input != STDIN_FILENO && dup2(input, STDIN_FILENO) < 0 )
		ft_throw("ERR_DUP2_EXECVE");
	if (output != STDOUT_FILENO && dup2(output, STDOUT_FILENO) < 0 )
		ft_throw("ERR_DUP2_EXECVE");
	execve(abs_path, cmd_arg, data->env);
	ft_throw(strerror(errno));
}

void	process(t_shell *data, t_tokens *token, int input, int output)
{
	char		**cmd_arg;
	int			nbr_arg;

	nbr_arg = 0;
	red_process(token, input, output, &nbr_arg);
	cmd_arg = get_args(token, nbr_arg);
	if (is_builtin(cmd_arg[0]))
		exec_builtin(data, cmd_arg);
	else
		ft_execve(data, cmd_arg, input, output);
}
