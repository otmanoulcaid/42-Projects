/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:09:07 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 14:09:07 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	l = *lst;
	if (!l)
		*lst = new;
	else
	{
		while (l->next)
			l = l->next;
		l->next = new;
	}
}
