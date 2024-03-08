/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:26:50 by tamehri           #+#    #+#             */
/*   Updated: 2024/03/08 23:40:32 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "struct.h"
# include "macros.h"
# include "../libft/libft.h"

# include <fcntl.h>             //open
# include <stdio.h>             //printf, perror
# include <stdlib.h>            //malloc, free, exit, getenv
# include <unistd.h>            //write, read, access, close, fork, unlink, execve, dup, dup2, pipe, chdir, getcwd, isatty, ttyname, ttyslot
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line. rl_redisplay, add_history
# include <readline/history.h>  // readline, rl_clear_history, rl_on_new_line, rl_replace_line. rl_redisplay, add_history
# include <signal.h>            //signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/wait.h>          //wait, waitpid, wait3, wait4
# include <sys/stat.h>          //stat, lstat, fstat
# include <dirent.h>            //opendir, closedir
# include <string.h>            //strerror
# include <errno.h>             //errno
# include <libc.h>
/*-----------------------parse-------------------------*/

int			is_space(int c);
int			is_operator(int c);
int			lexer(t_shell *data);
void		check_syntax(t_shell *data);
void    	command_tree(t_shell *data);
int			bunny_ears(char **s, char c);
int			ft_strcmp(char *s1, char *s2);
int			get_number_of_tokens(char *line);
int			expansion_value(char *str, int *i);
void		expand(char **s, char *tmp, int i[3]);

/*---------------------end_parse-----------------------*/

/*-------------------error_handling--------------------*/

int			throw_error(char *str);
void		ft_throw(char *strerr);
void		free_2d(char **strings);

/*-------------------error_handling--------------------*/

/*----------------environement_operation---------------*/

void		print(t_env *env);
t_env		*get_env(char **env);
void		env_clear(t_env **env);
t_env		*env_new(char *environ);
void		env_add_back(t_env **linked, t_env *node);

/*--------------end_environement_operation--------------*/

/*--------------------token_operation-------------------*/

t_tokens	*tokennew(char *content);
int			tokensize(t_tokens *lst);
void		tokenclear(t_tokens **lst);
void		token_class(t_tokens *token);
void		tokenadd_back(t_tokens **lst, t_tokens *new);
int			process_token(t_shell *data, t_tokens *token);
char		*init_token(char const *s, int *index, int lenght);

/*------------------end_token_operation-----------------*/

/*-------------------execute_operations-----------------*/
void		signals(void);
void		execute(t_shell *data);
int			is_builtin(t_tokens *token);
char		*absolute_path(char *cmd, char **env);
void		process(t_shell *data, t_tokens *token, int in, int out);
void		*red_process(t_tokens *token, int input, int output, int *nbr);
void		exec_builtin(t_shell *data, char **cmd_arg, int input, int output);

/*-----------------end_execute_operations---------------*/

/*--------------------built_in_command------------------*/

void		ft_pwd(void);
void		ft_exit(void);
void		ft_exit(void);
void		ft_cd(char *path);
void		ft_echo(char **av);
void		ft_env(t_env	*env);
void		unset(t_env **env, char **variable);
void		ft_export(t_env **env, char **to_add, int add);

/*------------------end_built_in_command----------------*/

#endif
