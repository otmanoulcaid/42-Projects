/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:34:16 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:37:44 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted_as(t_stack **a)
{
	t_node	*n;

	n = (*a)->head;
	while (n->next)
	{
		if (n->data > n->next->data)
			return (0);
		n = n->next;
	}
	return (1);
}

int	is_sorted_des(t_stack **a)
{
	t_node	*n;

	n = (*a)->head;
	while (n->next)
	{
		if (n->data < n->next->data)
			return (0);
		n = n->next;
	}
	return (1);
}

int	is_max(int i, t_stack **a)
{
	t_node	*n;

	n = (*a)->head->next;
	while (n)
	{
		if (i < n->data)
			return (0);
		n = n->next;
	}
	return (1);
}

int	is_min(int i, t_stack **a)
{
	t_node	*n;
	int		j;

	j = 0;
	n = (*a)->head;
	while (j++ < (*a)->qty)
	{
		if (i > n->data)
			return (0);
		n = n->next;
	}
	return (1);
}
