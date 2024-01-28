/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementary_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:08:28 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/06 00:53:25 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tree(t_stack **a, t_stack **b)
{
	t_node	*head;
	t_node	*tail;

	head = (*a)->head;
	tail = (*a)->tail;
	if (is_sorted_des(a))
	{
		rotate(a, "ra");
		swap(&((*a)->head->data), &((*a)->head->next->data), "sa");
	}
	else if (head->data > head->next->data && head->data < tail->data)
		swap(&head->data, &head->next->data, "sa");
	else if (head->data > head->next->data && head->next->data == (*a)->min)
		rotate(a, "ra");
	else if (head->data < head->next->data && head->data > tail->data)
		r_rotate(a, "rra");
	else
	{
		push_in(b, ft_pop(a), "pb");
		rotate(a, "ra");
		push_in(a, ft_pop(b), "pa");
	}
}

void	sort_less_5(t_stack **a, t_stack **b)
{
	if ((*a)->qty == 2 && (*a)->head->data > (*a)->tail->data)
		swap(&(*a)->head->data, &(*a)->tail->data, "sa");
	else if ((*a)->qty == 3)
		sort_tree(a, b);
	if ((*a)->qty > 2)
	{
		while ((*a)->qty > 3)
			push_in(b, ft_pop(a), "pb");
		if (!is_sorted_as(a))
			sort_tree(a, b);
		while ((*b)->head)
		{
			if (is_max((*b)->head->data, a))
				while ((*a)->min != (*a)->head->data)
					rotate(a, "ra");
			else
				while ((*a)->head->data < (*b)->head->data)
					rotate(a, "ra");
			push_in(a, ft_pop(b), "pa");
		}
	}
	while (!is_sorted_as(a))
		r_rotate(a, "rra");
}
