/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:08:57 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 14:08:57 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elm;

	elm = (t_list *)malloc(sizeof(t_list));
	if (!elm)
		return (NULL);
	elm->data = content;
	elm->next = NULL;
	return (elm);
}
