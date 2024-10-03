/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 07:45:16 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/03 23:54:43 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void    ft_echo(char **arg)
{
    int new_line;

    new_line = 0;
	arg++;
    if (*arg && !ft_strcmp(*arg, "-n"))
	{
		arg++;
        new_line = 1;
	}
    while (*arg)
    {
        printf("%s", *arg);
        if (*(arg + 1))
            printf(" ");
        arg++;
    }
    if (!new_line)
        printf("\n");
}

int     ft_cd(char **arg, t_env **env)
{
    char    *path;
	char	*cwd;

	// this fucking cd is wierd the too many arguments isn't as i thought it is
	cwd = getcwd(NULL,0);

    if (arg[1] && arg[2])
        return printf("cd : too many arguments\n%s\n", arg[1]);
    else if (!arg[1] || !arg[1][0])
        path = getenv("HOME");
    else
         path = arg[1];
    // update the env (PWD && OLDPWD) and free cwd 
	// you can use eport to do so but you have to use strjoin so more leaks to handle
    if (chdir(path) == -1)
		perror("chdir");
	return 0;
}

void    ft_pwd(void)
{
    char *pwd;

    pwd = getcwd(NULL, 0);
    if (pwd)
    {
        printf("%s\n", pwd);
        free(pwd);
    }
    else
        perror("pwd");
}

void	ft_env(t_env *env)
{
	while (env)
	{
		if (ft_strchr(env->env_line, '='))
			printf("%s\n", env->env_line);
		env = env->next;
	}
}
