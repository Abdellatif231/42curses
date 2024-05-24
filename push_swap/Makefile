CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = moves.c moves_I.c moves_II.c check_error.c
OFILES = $(CFILES:.c=.o)
NAME = push_swap
LIBFT = libft.a
PRINTF = libftprintf.a

all: $(PRINTF) $(LIBFT) $(NAME)

$(PRINTF):
	cd ./ft_printf && make
$(LIBFT):
	cd ./libft && make

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) ./libft/$(LIBFT) ./ft_printf/$(PRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES) $(OBONUS)
	cd ./libft && make clean
	cd ./ft_printf && make clean

fclean: clean
	rm -rf $(NAME)
	cd ./libft && make fclean
	cd ./ft_printf && make fclean

re: fclean all
