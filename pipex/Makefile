CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = parsing.c parsing_I.c parsing_II.c pipex.c pipex_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c
CBONUS = parsing.c parsing_I.c parsing_II.c pipex_bonus.c pipex_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
OBONUS = $(CBONUS:.c=.o)
NAME = pipex
LIBFT = libft.a
PRINTF = libftprintf.a

all: $(PRINTF) $(LIBFT) $(NAME)

$(PRINTF):
	cd ./ft_printf && make
$(LIBFT): 
	cd ./libft && make

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) ./libft/$(LIBFT) ./ft_printf/$(PRINTF) -o $(NAME)

bonus: $(PRINTF) $(LIBFT) $(OBONUS)
	$(CC) $(CFLAGS) $(OBONUS) ./libft/$(LIBFT) ./ft_printf/$(PRINTF) -o $(NAME)

%.o: %.c pipex.h
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
