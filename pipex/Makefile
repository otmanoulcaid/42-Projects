CC = cc
FLAGS = -Wall -Wextra -Werror

MAN = mandatory/main.c \
		mandatory/utils/pipex.c \
		mandatory/utils/cmds.c \
		mandatory/utils/utils.c \
		mandatory/utils/error.c
		
BONUS = bonus/main.c \
		bonus/utils/error.c \
		bonus/utils/pipex.c \
		bonus/utils/cmds.c \
		bonus/utils/utils.c \
		bonus/utils/here_doc.c

LIBFT =	libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strjoin.c \
		libft/ft_strnstr.c \
		libft/ft_strncmp.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_strdup.c

GNL = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

MAN_OBJ = $(MAN:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)
GNL_OBJ = $(GNL:.c=.o)

NAME = pipex
BONUS_NAME = pipex_bonus

mandatory/%.o : mandatory/%.c mandatory/pipex.h
	$(CC) $(FLAGS) -c $< -o $@

libft/%.o : libft/%.c libft/libft.h
	$(CC) $(FLAGS) -c $< -o $@

get_next_line/%.o : get_next_line/%.c get_next_line/get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/pipex_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(MAN_OBJ) $(LIBFT_OBJ)
	$(CC) $(MAN_OBJ) $(LIBFT_OBJ) -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ) $(LIBFT_OBJ) $(GNL_OBJ)
	$(CC) $(BONUS_OBJ) $(LIBFT_OBJ) $(GNL_OBJ) -o $(BONUS_NAME)

clean :
	rm -f $(MAN_OBJ) $(GNL_OBJ) $(BONUS_OBJ) $(LIBFT_OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : clean