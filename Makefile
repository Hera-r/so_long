CC=cc
NAME=so_long
SRC_FILES=main.c ft_utils.c ft_split.c ft_strlen.c get_next_line.c get_next_line_utils.c ft_wall.c ft_depthsearch.c ft_utils_dfs.c ft_map_valid.c ft_put_image.c ft_libft_tmp.c
OBJ=$(SRC_FILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


