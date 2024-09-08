CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFILES = main.c parssing.c utils.c
OFILES = $(CFILES:.c=.o)

all: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o philo

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf philo

re: fclean all
