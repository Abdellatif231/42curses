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

void    update_env(char *cwd, char *owd, t_env ** env)
{
    char    *pwd[4];

    pwd[0] = "export";
    pwd[1] = std_strjoin("PWD=", cwd);
    pwd[2] = std_strjoin("OLDPWD=", owd);
    pwd[3] = NULL;
    ft_export(pwd, env);
    free(pwd[1]);
    free(pwd[2]);
}

int     ft_cd(char **arg, t_env **env)
{
    char    *path;
    char    owd[PATH_MAX];
	char	cwd[PATH_MAX];
    char    *error1;
    char    *error2;

	error1 = getcwd(owd,sizeof(owd));
    if (arg[1] && arg[2])
    {
        ft_putstr_fd("cd : too many arguments\n", 2);
        return 1;
    }
    else if (!arg[1] || !arg[1][0])
        path = getenv("HOME");
    else
         path = arg[1];
    if (chdir(path) == -1)
    {
		perror("chdir");
	    return 1;
    }
    error2 = getcwd(cwd, sizeof(cwd));
    if (error1 && error2)
        update_env(cwd, owd, env);
    else
        ft_putstr_fd("error updating the env\n", 2);
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
