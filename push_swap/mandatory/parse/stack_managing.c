/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:52:26 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 22:49:46 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_pop(t_stack **a)
{
	t_node	*n;

	if (!a)
		return (NULL);
	n = (*a)->head;
	if ((*a)->qty == 1)
		return ((*a)->qty = 0, (*a)->head = NULL, (*a)->tail = NULL, n);
	(*a)->head = n->next;
	n->next = NULL;
	(*a)->head->prev = NULL;
	(*a)->qty -= 1;
	return (n);
}

void	ft_push(t_stack **a, t_node *n)
{
	if (!(*a)->head)
	{
		(*a)->qty = 1;
		(*a)->head = n;
		(*a)->tail = n;
		return ;
	}
	(*a)->qty += 1;
	n->next = (*a)->head;
	(*a)->head->prev = n;
	(*a)->head = n;
}

t_node	*pop_tail(t_stack **a)
{
	t_node	*n;

	if ((*a)->qty == 1)
		return (ft_pop(a));
	n = (*a)->tail;
	(*a)->tail = n->prev;
	(*a)->tail->next = NULL;
	n->prev = NULL;
	(*a)->qty -= 1;
	return (n);
}

void	push_tail(t_stack **a, t_node *n)
{
	if (!(*a)->qty)
	{
		(*a)->qty = 1;
		(*a)->head = n;
		(*a)->tail = n;
		return ;
	}
	(*a)->tail->next = n;
	n->prev = (*a)->tail;
	(*a)->tail = n;
	(*a)->qty += 1;
}
