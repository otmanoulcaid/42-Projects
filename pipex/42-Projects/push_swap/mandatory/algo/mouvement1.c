/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:33:49 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:37:55 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, char *s)
{
	t_node	*n;

	n = ft_pop(a);
	push_tail(a, n);
	n = NULL;
	n = ft_pop(b);
	push_tail(b, n);
	ft_putendl_fd(s, 1);
}

void	r_rotate_both(t_stack **a, t_stack **b, char *s)
{
	t_node	*n;

	n = pop_tail(a);
	ft_push(a, n);
	n = NULL;
	n = pop_tail(b);
	ft_push(b, n);
	ft_putendl_fd(s, 1);
}

void	rotate(t_stack **a, char *s)
{
	t_node	*n;

	n = ft_pop(a);
	push_tail(a, n);
	ft_putendl_fd(s, 1);
}

void	r_rotate(t_stack **a, char *s)
{
	t_node	*n;

	n = pop_tail(a);
	ft_push(a, n);
	ft_putendl_fd(s, 1);
}
