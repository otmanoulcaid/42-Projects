/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:39:10 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/02 01:25:56 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	if (ac < 5)
		return (perror("argument are less than 5"), 1);
	if (ac == 6 && !ft_strncmp(av[1], "here_doc", 8))
		here_doc(ac - 2, av + 2, env, &data);
	else
	{
		initialise(&data, av + 1, ac - 1);
		multiple_pipes(ac - 1, av + 1, env, &data);
	}
	return (EXIT_SUCCESS);
}
