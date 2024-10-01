/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 05:43:46 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/01 11:51:45 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	execute_left(t_tree *root, char **env, int fd[])
{
    dup2(fd[1], 1);
    close(fd[0]);
    exec(root, env);
//	free_tree(root);
    exit(1);
}

void    execute_right(t_tree *root, char **env, int fd[])
{
    dup2(fd[0], 0);
    close(fd[1]);
    exec(root, env);
//	free_tree(root);
    exit(1);
}

void	exec(t_tree *root, char **env)
{
	static int	exit_status = 0;
	int			fd[2];

	if (root == NULL)
		return ;
	if (root->word_token == PIPE)
	{
		pipe(fd);
		if (fork() == 0)
			execute_left(root->left, env, fd);
		if (fork() == 0)
			execute_right(root->right, env, fd);
		close(fd[0]);
		close(fd[1]);
		wait(&exit_status);
		wait(&exit_status);
	}
	else
	{
		simple_cmd(root, env);
	}
	return ;
}

int	strict_strncmp(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2) && !ft_strncmp(s1, s2, ft_strlen(s2)))
		return 1;
	return 0;
}

int	is_builtin(char *cmd)
{
	if (strict_strncmp(cmd, "echo"))
		return 1;
    if (strict_strncmp(cmd, "cd"))
        return 2;
    if (strict_strncmp(cmd, "pwd"))
        return 3;
    if (strict_strncmp(cmd, "pwd"))
        return 4;
    if (strict_strncmp(cmd, "export"))
        return 5;
    if (strict_strncmp(cmd, "unset"))
        return 6;
	if (strict_strncmp(cmd, "env"))
    	return 7;
    if (strict_strncmp(cmd, "exit"))
        return 8;
	return 0;
}

void	built_cmd(char **arg, char **farg)
{
	int	infd;
	int	outfd;

	infd = dup(0);
	outfd = dup(1);
	redirect_io(arg);
	if (is_builtin(*farg) == 1)
		ft_echo(farg++);
	else if (is_builtin(*farg) == 2)
		ft_cd(farg++);
	else if (is_builtin(*farg) == 3)
		ft_pwd();
	else if (is_builtin(*farg) == 8)
		ft_exit(farg + 1);
	dup2(infd, 0);
	dup2(outfd, 1);
}

void	simple_cmd(t_tree *root, char **env)
{
	char	**arg;
	char	**farg;
	char	*path;

	arg = generate_arg(root, env);
	farg = filter_arg(arg);
	if (farg && *farg && is_builtin(*farg))
		return built_cmd(arg, farg);
	if (fork() == 0)
	{
		redirect_io(arg);
		free_split(arg);
		if (!farg || !*farg)
			exit(1);
		path = check_path(farg[0], env);
		if (!path)
		{
			free_split(farg);
			exit(1);
		}
		execve(path, farg, env);
		perror("execve");
		free_split(farg);
		exit(1);
	}
	wait(NULL);
	free_split(arg);
	free_split(farg);
}
