/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:10:04 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:49:39 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../stack.h"

/*----------checker----------*/
int		checker(t_stack **a, t_stack **b);

/*----------err---------*/
int		check_error(char **av, t_stack **a);
int		double_exist(int nbr, t_stack **a);
void	failure(t_stack *a);

/*----------stack----------*/
t_stack	*creat_stack(void);
t_node	*ft_pop(t_stack **a);
t_node	*pop_tail(t_stack **a);
t_node	*get_min(t_stack **a);
t_node	*best_position(t_node *n, t_stack **b);
void	ft_push(t_stack **a, t_node *n);
void	indexing(t_stack **a);
void	push_tail(t_stack **a, t_node *n);
void	sort_less_5(t_stack **a, t_stack **b);
int		fill_stack(t_stack **a, char **str);
int		get_pos_in_stack(t_node *n, t_stack **a);

/*----------mouvements -----------*/
void	swap(int *a, int *b, char *s);
void	push_in(t_stack **a, t_node *b, char *s);
void	rotate(t_stack **a, char *s);
void	rotate_both(t_stack **a, t_stack **b, char *s);
void	r_rotate(t_stack **a, char *s);
void	r_rotate_both(t_stack **a, t_stack **b, char *s);
void	loop_rr(t_stack **a, t_stack **b);
void	loop_rrr(t_stack **a, t_stack **b);
void	loop_single(t_stack **a, t_stack **b, int cost_a, int cost_b);

/*---------utils-----------*/
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi_handler(const char *s, int *n);

/*---------bools----------*/
int		is_max(int i, t_stack **a);
int		is_min(int i, t_stack **a);
int		is_sorted_as(t_stack **a);
int		is_sorted_des(t_stack **a);

#endif
