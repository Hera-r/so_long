CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
SRC_FILES=main.c ft_utils.c ft_split.c ft_strlen.c get_next_line.c get_next_line_utils.c
OBJ_FILES=$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
