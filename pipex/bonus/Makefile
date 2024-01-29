CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		utils/error.c \
		utils/pipex.c \
		utils/cmds.c \
		utils/utils.c \
		utils/here_doc.c \
		../get_next_line/get_next_line.c \
		../get_next_line/get_next_line_utils.c

LIBFT =	../libft/ft_putstr_fd.c \
		../libft/ft_putendl_fd.c \
		../libft/ft_split.c \
		../libft/ft_strchr.c \
		../libft/ft_strjoin.c \
		../libft/ft_strnstr.c \
		../libft/ft_strncmp.c \
		../libft/ft_strlen.c \
		../libft/ft_substr.c \
		../libft/ft_strdup.c

OBJ = ${SRCS:.c=.o}
LIBFT_OBJ = ${LIBFT:.c=.o}

NAME = pipex

%.o : %.c pipex.h
	$(CC) $(FLAGS) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT_OBJ)
	$(CC) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all