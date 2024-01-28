/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:20:09 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/11 13:16:46 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(va_list args, int c, unsigned int *n)
{
	if (c == '%')
		ft_putchar(c, n);
	else
		ft_putchar(va_arg(args, int), n);
}
