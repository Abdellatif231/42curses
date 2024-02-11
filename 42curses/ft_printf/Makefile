CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_putadr.c ft_puthex.c ft_printf.c
NAME = libftprintf.a
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rsc  $(NAME) $(OFILES)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
