CC = cc
CFLAGS = #-fsanitize=address -g
CFILES = exec/check_path_I.c exec/exec_utils.c exec/safe_syscalls.c exec/builtins_I.c exec/unset.c exec/export.c exec/linked_list.c exec/utils.c exec/exit.c exec/builtins.c exec/execution.c exec/check_path.c exec/libft.c exec/get_args.c exec/redirection.c exec/split.c parsing/minishell.c parsing/expanding.c  utils/utils_0.c utils/utils_1.c  utils/utils_2.c utils/utils_3.c utils/org_helper.c utils/cmd_spliter.c utils/spliter_helper.c utils/tokenize.c utils/parse_helper.c parsing/syntax_checker_0.c parsing/syntax_checker_1.c parsing/parse.c 
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
