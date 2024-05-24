/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:58:53 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/18 15:23:40 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	out_file(t_va *va_l, char *av[], int ac)
{
	va_l->outfd = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (va_l->outfd == -1)
	{
		ft_putstr_fd(av[ac - 1], 2);
		perror(" ");
		return (1);
	}
	return (0);
}

int	open_files(t_va *va_l, char *av[], int ac)
{
	if (va_l->i == 3)
		return (out_file(va_l, av, ac));
	va_l->infd = open(av[1], O_RDONLY);
	if (va_l->infd == -1)
	{
		ft_putstr_fd(av[1], 2);
		perror(" ");
		return (1);
	}
	va_l->outfd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (va_l->outfd == -1)
	{
		ft_putstr_fd(av[ac - 1], 2);
		perror(" ");
		close(va_l->infd);
		return (1);
	}
	return (0);
}

void	pipe_error(void)
{
	perror("pipe");
	exit(1);
}

void	here_doc(t_va *va_l, char *limiter)
{
	char	*line;
	int		pfd[2];

	if (pipe(pfd) == -1)
		pipe_error();
	va_l->i = 3;
	va_l->prv_fd = dup(pfd[0]);
	close(pfd[0]);
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(0);
		if (!line)
			break ;
		if (!*limiter && *line == '\n')
			break ;
		if (ft_strlen(limiter) == ft_strlen(line) - 1 && !ft_strncmp(limiter,
				line, ft_strlen(line) - 1))
			break ;
		ft_putstr_fd(line, pfd[1]);
		free(line);
	}
	free(line);
	close(pfd[1]);
}

int	ft_close(t_va *va)
{
	close(va->prv_fd);
	close(va->fd[0]);
	close(va->fd[1]);
	close(va->infd);
	close(va->outfd);
	return (1);
}
