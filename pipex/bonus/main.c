/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:23:53 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/27 12:45:39 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check(void)
{
	system("leaks pipex");
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	atexit(check);
	if (ac < 5)
		return (perror("argument are less than 5"), 1);
	if (access(av[1], F_OK) || access(av[1], R_OK))
		ft_throw(strerror(errno));
	if (!ft_strncmp(av[1], "here_doc", 8))
		puts("heredoc");
	else
	{
		initialise(&data, av + 1, ac - 1);
		multiple_pipes(ac - 1, av + 1, env, &data);
	}
	return (close(data.in_fd), close(data.out_fd), 0);
}
