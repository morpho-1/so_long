NAME = so_long

CC = cc -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -f 

SRC = so_long.c check_map.c parse_map.c utils.c gnl/get_next_line.c \
	gnl/get_next_line_utils.c utils2.c check_path.c gnl/ft_printf.c\
	gnl/ft_putchar.c gnl/ft_puthexa.c gnl/ft_putnbr.c gnl/ft_putptr.c gnl/ft_putunbr.c \
	gnl/ft_putstr.c render_game.c ft_image.c

INCL = gnl/get_next_line.h so_long.h


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(MLX) $^ -o $@

%.o : %.c $(INCL)
	@$(CC) -c $< -o $@
	#Done

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all