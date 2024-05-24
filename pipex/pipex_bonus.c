/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:07:26 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/18 14:45:46 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	redirect_io(t_va *va_l, int ac)
{
	if (va_l->i != 2)
	{
		dup2(va_l->prv_fd, STDIN_FILENO);
		close(va_l->prv_fd);
	}
	else
	{
		dup2(va_l->infd, STDIN_FILENO);
		close(va_l->infd);
	}
	close(va_l->fd[0]);
	if (va_l->i != ac - 2)
	{
		dup2(va_l->fd[1], STDOUT_FILENO);
		close(va_l->fd[1]);
	}
	else
	{
		dup2(va_l->outfd, STDOUT_FILENO);
		close(va_l->outfd);
		close(va_l->fd[1]);
	}
}

int	execute_cmd(t_va *va_l, int ac, char *av[], char *ev[])
{
	redirect_io(va_l, ac);
	va_l->cmd = final_split(av[va_l->i], ' ');
	va_l->pathname = check_path(va_l->cmd[0], ev);
	if (va_l->pathname == NULL)
		return (free_split(va_l->cmd));
	execve(va_l->pathname, va_l->cmd, ev);
	return (1);
}

int	create_process(t_va *va_l, int ac, char *av[], char *ev[])
{
	if (pipe(va_l->fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	va_l->pid = fork();
	if (va_l->pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (va_l->pid == 0)
	{
		if (execute_cmd(va_l, ac, av, ev) == 1)
		{
			perror("execve");
			return (1);
		}
	}
	close(va_l->prv_fd);
	va_l->prv_fd = dup(va_l->fd[0]);
	close(va_l->fd[1]);
	close(va_l->fd[0]);
	return (0);
}

int	main(int ac, char *av[], char *ev[])
{
	t_va	va_l;

	va_l.i = 2;
	va_l.prv_fd = -1;
	if (ac < 5)
	{
		ft_putstr_fd("Error: Not enaugh argemment\n", 2);
		return (1);
	}
	if (!(ft_strncmp(av[1], "here_doc", ft_strlen("here_doc"))))
		here_doc(&va_l, av[2]);
	if (open_files(&va_l, av, ac) == 1)
		return (1);
	while (va_l.i < ac - 1)
	{
		if (create_process(&va_l, ac, av, ev) == 1)
			return (1);
		va_l.i++;
	}
	ft_close(&va_l);
	while (wait(NULL) > 0)
		;
	return (0);
}
