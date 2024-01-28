/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putValues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:03:31 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/12 14:01:37 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	in_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'x' || c == 'X' || c == 'd' 
		|| c == 'i' || c == 'u' || c == '%')
		return (1);
	return (0);
}

void	ft_put_values(const char *s, va_list args, unsigned int *n)
{
	while (*s)
	{
		while (*s && *s != '%')
		{
			ft_putchar(*s, n);
			s++;
		}
		if (*s && (*(s + 1) == 'c' || *(s + 1) == '%'))
			ft_char(args, *(s + 1), n);
		else if (*s && *(s + 1) == 's')
			ft_string(args, n);
		else if (*s && (*(s + 1) == 'i' || *(s + 1) == 'd' || *(s + 1) == 'u'))
			ft_decimal(args, s, n);
		else if (*s && *(s + 1) == 'p')
			ft_addr_handling(va_arg(args, void *), n);
		else if (*s && *(s + 1) == 'x')
			hexa_handling(va_arg(args, unsigned int), "0123456789abcdef", n);
		else if (*s && *(s + 1) == 'X')
			hexa_handling(va_arg(args, unsigned int), "0123456789ABCDEF", n);
		else if (*s && !in_format(*(s + 1)))
			s--;
		if (*s)
			s += 2;
	}
}
