CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
CFILES = main.c parssing.c utils.c routine.c setters.c check_death.c getters.c
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
