NAME = fractol

SRCS = sources/calculation.c \
sources/create.c \
sources/end.c \
sources/hook.c \
sources/main.c \
sources/move.c \
sources/plot.c \
sources/put_point.c \
sources/zoom.c

OBJ = calculation.o \
create.o \
end.o \
hook.o \
main.o \
move.o \
plot.o \
put_point.o \
zoom.o

INC = includes/fractol.h

FLAG = -Wall -Wextra -Werror

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIB = -L libft/ -lft

all: $(NAME)

$(NAME) :
	@make -C libft
	@clang $(FLAGS) -I $(INC) -c -O3 $(SRCS)
	@clang $(OBJ) $(LIB) $(MLX) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
