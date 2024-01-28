/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:17:40 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/27 12:46:50 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	swap(char **a, char **b)
{
	char	*help;

	help = *a;
	*a = *b;
	*b = help;
}

void	initialise(t_pipex *data, char **av, int ac)
{
	data->pid = (int *)malloc(sizeof(int) * (ac - 2));
	if (!data->pid)
		ft_throw(strerror(errno));
	data->out_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (data->out_fd < 0)
		ft_throw(strerror(errno));
	data->in_fd = open(av[0], O_RDONLY);
	if (data->in_fd < 0)
		ft_throw(strerror(errno));
}
