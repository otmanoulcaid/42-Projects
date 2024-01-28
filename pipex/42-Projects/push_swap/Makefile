# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:13:03 by ooulcaid          #+#    #+#              #
#    Updated: 2024/01/06 00:09:24 by ooulcaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc	
FLAGS = -Wall -Wextra -Werror

MANDATORY = mandatory/parse/error.c \
	   mandatory/parse/ft_atoi_handler.c \
	   mandatory/parse/stack_managing.c \
	   mandatory/parse/utils.c \
	   mandatory/algo/push_swap.c \
	   mandatory/algo/mouvement1.c \
	   mandatory/algo/mouvement2.c \
	   mandatory/algo/bools.c \
	   mandatory/algo/helper.c \
	   mandatory/algo/elementary_sort.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_split.c \
	   libft/ft_substr.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   
BONUS = bonus/main.c \
		bonus/checker.c \
		bonus/ft_strcmp.c \
		mandatory/parse/error.c \
		mandatory/parse/ft_atoi_handler.c \
		mandatory/parse/stack_managing.c \
		mandatory/parse/utils.c \
		mandatory/algo/mouvement1.c \
		mandatory/algo/mouvement2.c \
		mandatory/algo/bools.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_putendl_fd.c \
		libft/ft_split.c \
		libft/ft_substr.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
	   
OBJ = ${MANDATORY:.c=.o}

OBJB = ${BONUS:.c=.o}

EXEC = push_swap

EXECB = checker

all :  $(EXEC)

$(EXEC) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) mandatory/main.c -o $(EXEC)
	
%.o : %.c stack.h mandatory/push_swap.h bonus/push_swap_bonus.h
	@$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJB)
	@$(CC) $(OBJB) -o $(EXECB)

clean :
	rm -f $(OBJ) $(OBJB) mandatory/main.o

fclean : clean
	rm -f $(EXEC) $(EXECB)

re : fclean all bonus

