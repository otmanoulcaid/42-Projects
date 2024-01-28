/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:02:12 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 22:50:14 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_max_node(t_stack **a)
{
	t_node	*tmp;
	t_node	*max;

	tmp = (*a)->head;
	max = (*a)->head;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_node	*min_cost(t_stack **a)
{
	t_node	*min;
	t_node	*tmp;
	int		i;

	tmp = (*a)->head;
	min = (*a)->head;
	i = 0;
	while (i++ < (*a)->qty)
	{
		if (tmp->cost < min->cost)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	cheap_node(t_stack **a, t_stack **b)
{
	t_node	*tmp;
	t_node	*best;

	tmp = (*a)->head;
	while (tmp)
	{
		best = best_position(tmp, b);
		tmp->cost = (tmp->index + best->index + 1);
		tmp = tmp->next;
	}
	(*a)->cheapest_node = min_cost(a);
	if (is_min((*a)->cheapest_node->data, b))
		(*b)->cheapest_node = get_max_node(b);
	else
		(*b)->cheapest_node = best_position((*a)->cheapest_node, b);
}

void	all_top(t_stack **a, t_stack **b)
{
	int		cost_a;
	int		cost_b;

	cost_a = get_pos_in_stack((*a)->cheapest_node, a);
	cost_b = get_pos_in_stack((*b)->cheapest_node, b);
	if (cost_a > (*a)->qty / 2 && cost_b > (*b)->qty / 2)
		loop_rrr(a, b);
	else if (cost_a < (*a)->qty / 2 && cost_b < (*b)->qty / 2)
		loop_rr(a, b);
	else
		loop_single(a, b, cost_a, cost_b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_node	*max;

	push_in(b, ft_pop(a), "pb");
	push_in(b, ft_pop(a), "pb");
	if ((*b)->head->data < (*b)->tail->data)
		swap(&(*b)->head->data, &(*b)->tail->data, "sb");
	while ((*a)->head)
	{
		indexing(a);
		indexing(b);
		cheap_node(a, b);
		all_top(a, b);
		push_in(b, ft_pop(a), "pb");
	}
	max = get_max_node(b);
	if (max->index > (*b)->qty / 2)
		while (!is_sorted_des(b))
			r_rotate(b, "rrb");
	else
		while (max->data != (*b)->head->data)
			rotate(b, "rb");
	while ((*b)->qty)
		push_in(a, ft_pop(b), "pa");
}
