# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:13:03 by ooulcaid          #+#    #+#              #
#    Updated: 2023/11/12 14:09:12 by ooulcaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_putnbr_fd.c ft_char.c ft_addr_handling.c ft_hexa_handling.c \
		ft_putValues.c ft_putstr_fd.c ft_decimal.c ft_printf.c \
		ft_putchar_fd.c ft_str.c

OBJ = ${SRCS:.c=.o}

NAME = libftprintf.a

all : $(NAME) 

$(NAME) : $(OBJ)
	ar -crs $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all

