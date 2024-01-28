/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:05:57 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/27 23:09:42 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	swap(char **a, char **b)
{
	char	*help;

	help = *a;
	*a = *b;
	*b = help;
}

void	init(int ac, char **av, t_pipex *data)
{
	data->fd_in = open(av[0], O_RDONLY);
	if (data->fd_in < 0)
		ft_throw(strerror(errno));
	data->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_out < 0)
		ft_throw(strerror(errno));
}
