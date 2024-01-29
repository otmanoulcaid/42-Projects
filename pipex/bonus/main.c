/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:23:53 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/29 11:28:34 by codespace        ###   ########.fr       */
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

	//atexit(check);
	if (ac < 5)
		return (perror("argument are less than 5"), 1);
	if (ac == 6 && !ft_strncmp(av[1], "here_doc", 8))
		here_doc(ac - 2, av + 2, env, &data);
	else
	{
		initialise(&data, av + 1, ac - 1);
		multiple_pipes(ac - 1, av + 1, env, &data);
	}
	return (close(data.in_fd), close(data.out_fd), 0);
}
