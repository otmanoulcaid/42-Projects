CC = cc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS=-I /usr/local/include -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \
	mandatory/parse/extract_data.c \
	mandatory/parse/file_extention.c \
	mandatory/parse/error.c \
	mandatory/fdf.c \

UTILS = libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strncmp.c \
		libft/ft_strrchr.c \
		libft/ft_putendl_fd.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstadd_back_bonus.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ = ${SRCS:.c=.o}
UTILS_OBJ = ${UTILS:.c=.o}

NAME = fdf


all : $(NAME)

$(NAME) : $(OBJ) $(UTILS_OBJ)
	$(CC) $(OBJ) $(UTILS_OBJ) -o $(NAME) $(MLXFLAGS)
#rm -f $(OBJ)

%.o : %.c fdf.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(UTILS_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all