CC = cc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS= -lmlx -framework OpenGL -framework AppKit libmlx42.a

MAN = mandatory/main.c \
	mandatory/parse/extract_data.c \
	mandatory/parse/file_extention.c \
	mandatory/parse/error.c \
	mandatory/parse/fdf.c

LIBFT = libft/ft_atoi.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strncmp.c \
		libft/ft_strrchr.c \
		libft/ft_putendl_fd.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstadd_back_bonus.c

GNL = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

MAN_OBJ = $(MAN:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)
GNL_OBJ = $(GNL:.c=.o)

NAME = fdf

mandatory/%.o : mandatory/%.c mandatory/fdf.h
	$(CC) $(FLAGS) -c $< -o $@

libft/%.o : libft/%.c libft/libft.h
	$(CC) $(FLAGS) -c $< -o $@

get_next_line/%.o : get_next_line/%.c get_next_line/get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(MAN_OBJ) $(LIBFT_OBJ) $(GNL_OBJ)
	$(CC) $(MAN_OBJ) $(LIBFT_OBJ) $(GNL_OBJ) -o $(NAME) $(MLXFLAGS) -I includes

# bonus : $(BONUS_NAME)

clean :
	rm -f $(MAN_OBJ) $(GNL_OBJ) $(LIBFT_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean