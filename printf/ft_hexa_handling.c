/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:44:38 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/11 13:20:31 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexa_handling(unsigned long ui, const char *s, unsigned int *n)
{
	if (ui < 0)
		hexa_handling(-ui, s, n);
	if (ui < 16)
		ft_putchar(*(s + ui), n);
	else
	{
		hexa_handling(ui / 16, s, n);
		ft_putchar(*(s + (ui % 16)), n);
	}
}
