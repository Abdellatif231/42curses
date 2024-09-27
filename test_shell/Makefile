CC = cc
CFLAGS = #-fsanitize=address
CFILES = exec/check_path.c exec/libft.c exec/split.c exec/execution.c exec/get_args.c exec/redirection.c  parsing/minishell.c utils/cmd_spliter.c utils/utils.c utils/tokenize.c utils/parse_helper.c parsing/syntax_checker_0.c parsing/syntax_checker_1.c parsing/parse.c 
OFILES = $(CFILES:.c=.o)
NAME = minishell
all: $(NAME)
$(OFILES): %.o: %.c includes/minishell.h
	$(CC) -c $< -o $@
$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -lreadline -o $(NAME)
clean:
	rm -rf $(OFILES)
fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)
