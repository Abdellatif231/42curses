/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:29:41 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/20 13:13:22 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_cmd(t_va *va, char *av[], int ac, char *ev[])
{
	va->cmd = final_split(av[ac - 3], ' ');
	if (!va->cmd)
		return (ft_close(va));
	va->pathname = check_path(va->cmd[0], ev);
	if (va->pathname == NULL)
	{
		free_split(va->cmd);
		return (ft_close(va));
	}
	dup2(va->infd, STDIN_FILENO);
	dup2(va->fd[1], STDOUT_FILENO);
	ft_close(va);
	if (execve(va->pathname, va->cmd, ev) == 1)
	{
		free_split(va->cmd);
		perror(" ");
	}
	return (1);
}

int	second_cmd(t_va *va, char *av[], int ac, char *ev[])
{
	va->cmd = final_split(av[ac - 2], ' ');
	if (!va->cmd)
		return (ft_close(va));
	va->pathname = check_path(va->cmd[0], ev);
	if (va->pathname == NULL)
	{
		free_split(va->cmd);
		return (ft_close(va));
	}
	dup2(va->outfd, STDOUT_FILENO);
	dup2(va->fd[0], STDIN_FILENO);
	ft_close(va);
	if (execve(va->pathname, va->cmd, ev) == 1)
	{
		free_split(va->cmd);
		perror(" ");
	}
	return (1);
}

void	parent(t_va *va)
{
	ft_close(va);
	while (wait(NULL) > 0)
		;
}

int	main(int ac, char *av[], char *ev[])
{
	t_va	va;

	if (ac < 5 || ac > 5)
	{
		ft_putstr_fd("Error: The program takes only 4 arguments\n", 2);
		return (1);
	}
	va.i = 0;
	if (open_files(&va, av, ac) == 1)
		return (1);
	if (pipe(va.fd) == -1)
		pipe_error();
	va.pid1 = fork();
	if (va.pid1 == -1)
		return (ft_close(&va));
	if (va.pid1 == 0)
		return (first_cmd(&va, av, ac, ev));
	va.pid2 = fork();
	if (va.pid2 == -1)
		return (ft_close(&va));
	if (va.pid2 == 0)
		return (second_cmd(&va, av, ac, ev));
	parent(&va);
	return (0);
}
