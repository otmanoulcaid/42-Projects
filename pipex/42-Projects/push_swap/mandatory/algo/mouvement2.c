/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:58:07 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:37:59 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_in(t_stack **a, t_node *n, char *s)
{
	ft_push(a, n);
	ft_putendl_fd(s, 1);
}

void	swap(int *a, int *b, char *s)
{
	int	h;

	h = *a;
	*a = *b;
	*b = h;
	ft_putendl_fd(s, 1);
}
