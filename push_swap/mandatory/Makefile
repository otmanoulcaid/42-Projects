# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:13:03 by ooulcaid          #+#    #+#              #
#    Updated: 2024/01/04 15:45:55 by ooulcaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc	
FLAGS = -Wall -Wextra -Werror

SRCS = parse/error.c \
	   parse/ft_atoi.c \
	   parse/ft_split.c \
	   parse/ft_strdup.c \
	   parse/ft_strlen.c \
	   parse/ft_substr.c \
	   parse/stack_managing.c \
	   parse/utils.c \
	   parse/ft_putendl_fd.c \
	   algo/push_swap.c \
	   algo/mouvement1.c \
	   algo/mouvement2.c \
	   algo/bools.c \
	   algo/helper.c \
	   algo/elementary_sort.c \
	   main.c
	   
OBJ = ${SRCS:.c=.o}

EXEC = push_swap

all :  $(EXEC)

$(EXEC) : $(OBJ) 
	@$(CC) $(OBJ) -o $(EXEC)
	
%.o : %.c push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXEC)

re : fclean all

