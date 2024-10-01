/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 07:45:16 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/01 09:44:18 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void    ft_echo(char **arg)
{
    int new_line;

    new_line = 0;
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

int     ft_cd(char **arg)
{
    char    *path;
	char	*cwd;

	cwd = getcwd(NULL,0);

    if (arg[1] && arg[2])
        printf("cd : too many arguments\n%s\n", arg[1]);
    else if (!arg[1] || !arg[1][0])
        path = getenv("HOME");
    else
         path = arg[1];
    // update the env (PWD && OLDPWD) and free cwd
    return chdir(path);
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
