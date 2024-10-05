/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:14:32 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/05 22:31:18 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	strict_strncmp(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2) && !ft_strncmp(s1, s2, ft_strlen(s2)))
		return (1);
	return (0);
}

static void	ft_tolower(char *c)
{
	if (*c >= 65 && *c <= 90)
		*c += 32;
}

int	is_builtin(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		ft_tolower(&cmd[i++]);
	if (strict_strncmp(cmd, "echo"))
		return (1);
	if (strict_strncmp(cmd, "cd"))
		return (2);
	if (strict_strncmp(cmd, "pwd"))
		return (3);
	if (strict_strncmp(cmd, "export"))
		return (4);
	if (strict_strncmp(cmd, "unset"))
		return (5);
	if (strict_strncmp(cmd, "env"))
		return (6);
	if (strict_strncmp(cmd, "exit"))
		return (7);
	return (0);
}

void	built_cmd(char **arg, char **fltr_arg, t_glob *glob)
{
	int	infd;
	int	outfd;
	int	type;

	infd = dup(0);
	outfd = dup(1);
	redirect_io(arg);
	type = is_builtin(*fltr_arg);
	if (type == 1)
		ft_echo(fltr_arg);
	if (type == 2)
		ft_cd(fltr_arg, glob->env);
	if (type == 3)
		ft_pwd();
	if (type == 4)
		ft_export(fltr_arg, glob->env);
	if (type == 5)
		ft_unset(fltr_arg, glob->env);
	if (type == 6)
		ft_env(*glob->env);
	else if (type == 7)
		ft_exit(fltr_arg);
	dup2(infd, 0);
	dup2(outfd, 1);
}
