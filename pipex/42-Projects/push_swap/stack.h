/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:46:42 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/06 00:51:27 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

typedef struct s_node
{
	int				cost;
	int				index;
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		qty;
	int		min;
	t_node	*cheapest_node;
	t_node	*head;
	t_node	*tail;
}	t_stack;

#endif