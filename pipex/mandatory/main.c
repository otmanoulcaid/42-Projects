/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:40:16 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/30 19:15:16 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	if (ac < 5)
		ft_throw("arguments less than 5");
	init(ac - 1, av + 1, &data);
	if (pipe(data.pipe) < 0)
		ft_throw(strerror(errno));
	pipex(av + 1, env, &data);
	return (0);
}
