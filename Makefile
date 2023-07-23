CC=cc
NAME=so_long
SRC_FILES=main.c\
		ft_utils.c ft_split.c ft_strlen.c get_next_line.c get_next_line_utils.c ft_wall.c ft_depthsearch.c ft_utils_dfs.c ft_map_valid.c ft_put_image.c ft_libft_tmp.c ft_move.c
OBJ=$(SRC_FILES:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -ggdb -c $< -o $@

$(NAME): $(OBJ) mlx_linux/libmlx.a
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -ggdb -o $(NAME)

mlx_linux/libmlx.a:
	make -C mlx_linux

clean:
	rm -f $(OBJ)
	make clean -C mlx_linux

fclean: clean
	rm -f $(NAME)


re: fclean all



.PHONY: all clean fclean re


