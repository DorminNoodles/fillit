NAME = fillit
CC = gcc
INC = includes/
FLAGS = -Wall -Wextra -Werror
SRC_NAME =	convert_tetro.c					\
			check_file.c					\
			check_pos.c						\
			backtracking.c					\
			check_tetro.c					\
			fillit.c						\
			file.c							\
			check_square_size.c				\
			grid.c							\

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(SRC) -I $(INC) libft/libft.a -o $(NAME) $(FLAGS)

test :
	gcc $(SRC) -I includes libft.a -o debug

clean :
	rm -f $(OBJ)
	@make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean

re : fclean all

.PHONY: all clean fclean re
