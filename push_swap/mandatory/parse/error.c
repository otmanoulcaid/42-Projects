/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:38:00 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/06 00:52:28 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_strs(char **str)
{
	int	i;

	i = 0;
	while (*(str + i))
		free(*(str + i++));
	free(str);
}

void	failure(t_stack *a)
{
	t_node	*tmp;
	t_node	*n;

	tmp = a->head;
	while (tmp)
	{
		n = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = n;
	}
	free(a);
	a = NULL;
}

int	check_error(char **av, t_stack **a)
{
	int		i;
	char	**strs;

	i = 1;
	strs = NULL;
	while (*(av + i))
	{
		if (av[i][0])
		{
			strs = ft_split(*(av + i), ' ');
			if (!strs)
				return (failure(*a), 0);
			if (!*strs || !fill_stack(a, strs))
				return (failure(*a), free_strs(strs), 0);
			free_strs(strs);
		}
		i++;
	}
	return (1);
}

int	double_exist(int nbr, t_stack **a)
{
	t_node	*n;

	n = (*a)->head;
	while (n)
	{
		if (nbr == n->data)
			return (1);
		n = n->next;
	}
	return (0);
}
