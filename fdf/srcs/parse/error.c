/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:55 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/28 16:00:11 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->cord[i++]);
	ft_lstclear(&map->list, free);
	free((map->cord));
	free(map);
}

void	ft_throw(char *strerr)
{
	ft_putendl_fd(strerr, 2);
	exit(EXIT_FAILURE);
}

void	faillure(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		(free(str[i]), str[i++] = NULL);
	free(str);
}
