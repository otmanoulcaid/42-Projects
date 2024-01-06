/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:53:43 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:37:27 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_pos_in_stack(t_node *n, t_stack **a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = (*a)->head;
	while (i < (*a)->qty)
	{
		if (tmp->data == n->data)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	loop_rrr(t_stack **a, t_stack **b)
{
	while ((*a)->head->data != (*a)->cheapest_node->data
		&& (*b)->head->data != (*b)->cheapest_node->data)
		r_rotate_both(a, b, "rrr");
	while ((*a)->head->data != (*a)->cheapest_node->data)
		r_rotate(a, "rra");
	while ((*b)->head->data != (*b)->cheapest_node->data)
		r_rotate(b, "rrb");
}

void	loop_rr(t_stack **a, t_stack **b)
{
	while ((*a)->head->data != (*a)->cheapest_node->data
		&& (*b)->head->data != (*b)->cheapest_node->data)
		rotate_both(a, b, "rr");
	while ((*a)->head->data != (*a)->cheapest_node->data)
		rotate(a, "ra");
	while ((*b)->head->data != (*b)->cheapest_node->data)
		rotate(b, "rb");
}

void	loop_single(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > (*a)->qty / 2)
	{
		while ((*a)->head->data != (*a)->cheapest_node->data)
			r_rotate(a, "rra");
	}
	else
	{
		while ((*a)->head->data != (*a)->cheapest_node->data)
			rotate(a, "ra");
	}
	if (cost_b > (*b)->qty / 2)
	{
		while ((*b)->head->data != (*b)->cheapest_node->data)
			r_rotate(b, "rrb");
	}
	else
	{
		while ((*b)->head->data != (*b)->cheapest_node->data)
			rotate(b, "rb");
	}
}

t_node	*best_position(t_node *n, t_stack **b)
{
	t_node	*big_small;
	t_node	*tmp;

	big_small = get_min(b);
	tmp = (*b)->tail;
	while (tmp)
	{
		if (tmp->data < n->data && tmp->data > big_small->data)
			big_small = tmp;
		tmp = tmp->prev;
	}
	return (big_small);
}
