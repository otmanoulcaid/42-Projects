CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		utils/pipex.c \
		utils/cmds.c \
		utils/utils.c \
		utils/error.c

UTILS =	../libft/ft_putstr_fd.c \
		../libft/ft_putendl_fd.c \
		../libft/ft_split.c \
		../libft/ft_strchr.c \
		../libft/ft_strjoin.c \
		../libft/ft_strnstr.c \
		../libft/ft_strlen.c \
		../libft/ft_substr.c \
		../libft/ft_strdup.c \

OBJ = ${SRCS:.c=.o}
UTILS_OBJ = ${UTILS:.c=.o}

NAME = pipex

%.o : %.c pipex.h
	$(CC) $(FLAGS) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(OBJ) $(UTILS_OBJ)
	$(CC) $(OBJ) $(UTILS_OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) $(UTILS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all