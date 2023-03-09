NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a

SRC = src/fractol.c \
	src/hook.c \
	src/params.c \
	src/julia.c \
	src/mandelbrot.c \
	src/complex_math.c \
	src/params.c \
	#burning.c \


all: $(NAME)

$(NAME): $(/src SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./libft
	echo "\033[1m LIBFT done \033[0m"
	$(MAKE) --no-print-directory -C ./minilibx-linux
	echo "\033[1m MiniLibX done \033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m Ready to FRACT-OL \033[0m"

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: