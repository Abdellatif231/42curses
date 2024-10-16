/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:57:15 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/13 18:20:17 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*add_char(char *line, char c)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(sizeof(char) * (ft_strlen(line) + 2));
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i++] = c;
	new_line[i] = '\0';
	return (new_line);
}

void	sub_prs(t_token *node, t_glob *glob, char *file)
{
	char	*line;
	char	*new_line;
	int		fd;

	hdoc_signals();
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = readline(">");
		if (!line)
			break ;
		if (!*node->next->word && !*line)
			break ;
		if (strict_strncmp(node->next->word, line))
			break ;
		if (expand_triger(node->next->word))
			line = heredoc_expand(line, *glob->env);
		new_line = add_char(line, '\n');
		ft_putstr_fd(new_line, fd);
		free(line);
		free(new_line);
	}
	close(fd);
	free(line);
	exit(0);
}

void	hd_exit_status(int wstatus, t_glob *glob)
{
	if (WIFSIGNALED(wstatus))
	{
		glob->exit_status = WTERMSIG(wstatus);
		if (glob->exit_status == SIGINT)
		{
			G_VAR = 1;
			glob->exit_status = 1;
		}
	}
}

void	x_hdoc(t_token *node, t_glob *glob, char *file)
{
	int	pid;
	int	wstatus;

	pid = ft_fork();
	if (pid == 0)
		sub_prs(node, glob, file);
	else
	{
		waitpid(pid, &wstatus, 0);
		hd_exit_status(wstatus, glob);
		free(node->next->word);
		node->next->word = ft_strdup(file);
	}
}

void	here_doc(t_token *node, t_glob *glob)
{
	char	*file;
	char	*new_file;
	int		c;

	G_VAR = 0;
	file = ft_strdup("/tmp/.HeRe_DoC");
	c = 'a';
	while (node)
	{
		if (node->word_token == PIPE)
		{
			new_file = add_char(file, c);
			free(file);
			file = new_file;
			c++;
		}
		if (node->word_token == HEREDOC)
			x_hdoc(node, glob, file);
		if (G_VAR)
			break ;
		node = node->next;
	}
	free(file);
}
