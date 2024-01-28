/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:59:11 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/12 14:12:23 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int				availiable(void);
void			ft_putchar(char c, unsigned int *n);
void			ft_putstr(const char *s, unsigned int *n);
void			ft_putnbr(long l, unsigned int *n);
unsigned int	ft_printf(const char *s, ...);
void			ft_put_values(const char *s, va_list args, unsigned int *n);
void			ft_char(va_list args, int c, unsigned int *n);
void			ft_string(va_list args, unsigned int *n);
void			ft_decimal(va_list args, const char *s, unsigned int *n);
void			ft_addr_handling(void *p, unsigned int *n);
void			hexa_handling(unsigned long l, const char *s, unsigned int *n);

#endif