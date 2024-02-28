/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:08:20 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/28 13:27:35 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c, int *words);
void	ft_putendl_fd(char *s, int fd);
int		is_upper(char c);
int		is_lower(char c);
int		ft_atoi_base(char *str);
char	**get_lines(int fd, int *lines);
void	ft_throw(char *err_msg);

typedef struct s_list
{
	int				length;
	void			*data;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif
