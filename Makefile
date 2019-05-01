NAME = fractol

SRCS = sources/*.c

OBJ = *.o

INC = includes/fractol.h

FLAG = -Wall -Wextra -Werror

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIB = -L libft/ -lft

all: $(NAME)

$(NAME) :
	@make -C libft
	@clang -I $(INC) -c -O3 $(SRCS)
	@clang $(OBJ) $(LIB) $(MLX) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
