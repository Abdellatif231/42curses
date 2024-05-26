CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = check_leaks.c  main.c moves.c moves_I.c moves_II.c check_error.c utils.c sort.c bubble_sort.c
OFILES = $(CFILES:.c=.o)
NAME = push_swap
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd ./libft && make

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) ./libft/$(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES) $(OBONUS)
	cd ./libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re
