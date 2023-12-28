/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:15:09 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/13 10:39:07 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	availiable(void)
{
	if (write(1, "", 0) < 0)
		return (0);
	return (1);
}

unsigned int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	chars;

	if (!availiable())
		return (-1);
	chars = 0;
	va_start(args, s);
	ft_put_values(s, args, &chars);
	va_end(args);
	return (chars);
}
