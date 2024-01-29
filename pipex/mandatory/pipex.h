/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:39:49 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/27 12:52:21 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		pipe[2];
	int		pid[2];
	int		fd_in;
	int		fd_out;
	char	**cmd;
}	t_pipex;

/*---------error----------*/

void	ft_throw(char *error);
void	failure(char **str);
void	init(int ac, char **av, t_pipex *data);
void	swap(char **a, char **b);
void	process(int input, int output, char *av, char **env);
void	pipex(char **av, char **env, t_pipex *data);
char	**get_cmd(char *av, char **env);

#endif