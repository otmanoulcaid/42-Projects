/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:53:11 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/29 10:35:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h> 
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"


typedef struct s_pipex
{
	int		*pid;
	int		in_fd;
	int		out_fd;
	int		pipe[2];
}	t_pipex;

/*---------error----------*/

void	failure(char **str);
void	process(int input, int output, char *av, char **env);
char	**get_cmd(char *av, char **env);
char	*valid_cmd(char *cmd, char **bins);
void	multiple_pipes(int ac, char **av, char **env, t_pipex *data);
void    here_doc(int ac, char **av, char **env, t_pipex *data);
void	initialise(t_pipex *data, char **av, int ac);
void	ft_throw(char *strerr);
void	swap(char **a, char **b);

#endif