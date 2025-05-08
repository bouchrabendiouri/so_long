NAME = so_long

SRC = check_map.c ft_split.c game.c get_next_line.c move.c so_long.c main.c tools.c

CC = cc

CFLAGS = -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework Appkit

all : ${NAME}

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re : fclean all
