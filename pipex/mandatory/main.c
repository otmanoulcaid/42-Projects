/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:23:53 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/28 01:16:42 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check(void)
{
	system("leaks pipex");
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	//atexit(check);
	if (ac < 5)
		ft_throw("arguments less than 5");
	init(ac - 1, av + 1, &data);
	pipex(av + 1, env, &data);
	return (0);
}
