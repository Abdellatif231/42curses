CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = main.c utils.c utils_I.c parsing.c event.c
OFILES = $(CFILES:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
