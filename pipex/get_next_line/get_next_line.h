/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:29:27 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/29 10:54:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_gl(char	**buf);
int		read_swap(char **buf, int fd, int *check);
// char	*strjoin(char *s1, char *s2);
int		get_index(char *s);
int		exist(char *s);
void	ft_cpy(char *dst, char *src, unsigned int len);
void	change(char **s1, char **s2);

#endif