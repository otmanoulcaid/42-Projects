/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:38:25 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:35:07 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*creat_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->qty = 0;
	s->cheapest_node = NULL;
	s->head = NULL;
	s->tail = NULL;
	return (s);
}

t_node	*new_node(int i)
{
	t_node		*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->data = i;
	n->next = NULL;
	n->prev = NULL;
	n->index = 0;
	n->cost = 0;
	return (n);
}

t_node	*get_min(t_stack **a)
{
	t_node	*tmp;
	t_node	*min;

	tmp = (*a)->head;
	min = (*a)->head;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	fill_stack(t_stack **a, char **str)
{
	int		i;
	int		nbr;
	t_node	*n;

	i = 0;
	while (*(str + i))
	{
		if (!ft_atoi_handler(*(str + i), &nbr) || double_exist(nbr, a))
			return (0);
		n = new_node(nbr);
		if (!n)
			return (0);
		push_tail(a, n);
		i++;
	}
	(*a)->min = get_min(a)->data;
	return (1);
}

void	indexing(t_stack **a)
{
	int		i;
	t_node	*tmp;

	tmp = (*a)->head;
	i = 0;
	while (tmp)
	{
		if (i < (*a)->qty / 2)
			tmp->index = i++;
		else
			tmp->index = (*a)->qty - i++;
		tmp = tmp->next;
	}
}
