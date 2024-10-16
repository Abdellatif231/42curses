/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:15:05 by bbelarra42        #+#    #+#             */
/*   Updated: 2024/10/13 18:17:36 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	G_VAR = 0;

int	main(int ac, char *av[], char *env[])
{
	t_env	*our_env;
	t_glob	glob;

	our_env = env_dup(env);
	glob.env = &our_env;
	glob.exit_status = 0;
	setup_main_signals();
	while (1)
		parsing_entry(readline("0xhb_shell$ "), &glob);
}

void	parsing_entry(char *parse_string, t_glob *glob)
{
	t_token	*head;
	t_tree	*root;
	char	**organized_input;

	add_history(parse_string);
	if (!parse_string)
	{
		printf("exit\n");
		exit(0);
	}
	else if (syntax_checker(parse_string))
	{
		printf("syntax error\n");
		glob->exit_status = 25;
		free(parse_string);
		return ;
	}
	organized_input = input_organizer(parse_string);
	head = lexer(organized_input);
	expand_flager(head, *glob->env);
	content_trima(head);
	here_doc(head, glob);
	if (G_VAR)
	{
		printf("EXIT_STATUS: %d\n", glob->exit_status);
		return;
	}
	root = parse(head);
	exec(root, glob);
	printf("EXIT_STATUS: %d\n", glob->exit_status);
	//	unlink("/tmp/");
	//	print_tree(root, 0);
	// link_free(head);
}

int	trim_flager(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == 34 || string[i] == 39 || string[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}

void	content_trima(t_token *head)
{
	t_trim	trim;

	trim.closed = 1;
	trim.i = 0;
	trim.current = head;
	while (trim.current)
	{
		trim.y = 0;
		trim.i = 0;
		if (trim_flager(trim.current->word))
		{
			trim.trimed = malloc(ft_strlen(trim.current->word) + 1);
			while (trim.current->word[trim.i])
			{
				trim_whiler(&trim);
				trim.i++;
			}
			trim.trimed[trim.y] = '\0';
			free(trim.current->word);
			trim.current->word = trim.trimed;
		}
		trim.current = trim.current->next;
	}
}

t_token	*lexer(char **organized_input)
{
	t_tokvar	tok_var;

	tok_var.i = 0;
	tok_var.head = NULL;
	while (organized_input[tok_var.i])
	{
		tok_var.word_token = identifier(organized_input[tok_var.i]);
		tok_var.new_token = token_initializer(tok_var.word_token,
				organized_input[tok_var.i]);
		if (!tok_var.head)
		{
			tok_var.head = tok_var.new_token;
			tok_var.current = tok_var.new_token;
		}
		else
		{
			tok_var.current->next = tok_var.new_token;
			tok_var.current = tok_var.new_token;
		}
		free(organized_input[tok_var.i]);
		tok_var.i++;
	}
	free(organized_input[tok_var.i]);
	free(organized_input);
	return (tok_var.head);
}
