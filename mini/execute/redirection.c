/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:10:57 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/08 23:49:40 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	input_red(char *file, int input, int output)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_throw("ERROR_OPEN_REDIRECTION_PROCESS");
	if (dup2(fd, output) < 0)
		ft_throw("ERROR_DUP2_REDIRECTION_PROCESS");
}

static void	output_red(char *file, int input, int output)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_throw("ERROR_OPEN_REDIRECTION_PROCESS");
	if (dup2(fd, output) < 0)
		ft_throw("ERROR_DUP2_REDIRECTION_PROCESS");
}

static void	append_red(char *file, int input, int output)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		ft_throw("ERROR_OPEN_REDIRECTION_PROCESS");
	if (dup2(fd, output) < 0)
		ft_throw("ERROR_DUP2_REDIRECTION_PROCESS");
}

static	void	herdoc_red(char *eof, int input, int output)
{
	int	fd;

	fd = hedoc();
	if (fd < 0)
		ft_throw("ERROR_HERDOC_REDIRECTION_PROCESS");
	if (dup2(fd, output) < 0)
		ft_throw("ERROR_DUP2_REDIRECTION_PROCESS");
}

void	*red_process(t_tokens *token, int input, int output, int *nbr)
{
	while (token && token->string[0] != '|')
	{
		if (token->class == APPEND && token->right->string[0] != '|')
			(append_red(token->right->string, input, output),
				token = token->right);
		else if (token->class == OUTPUT_RED && token->right->string[0] != '|')
		{
			token = token->right;
			append_red(token->string, input, output);
		}
		else if (token->class == INPUT_RED && token->right->string[0] != '|')
		{
			token = token->right;
			append_red(token->string, input, output);
		}
		else if (token->class == HEREDOC && token->right->string[0] != '|')
		{
			token = token->right;
			herdoc_red(token->string, input, output);
		}
		else if (token->class == WORD)
			(*nbr)++;
		token = token->right;
	}
}
