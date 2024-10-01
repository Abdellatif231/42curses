/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:51:08 by amaaouni          #+#    #+#             */
/*   Updated: 2024/10/01 11:55:40 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int is_numeric(const char *str)
{
    int	i;

	i = 0;
    if (str[0] == '-' || str[0] == '+')
		i++;
    while (str[i])
	{
        if (!ft_isdigit(str[i]))
            return 0;
		i++;
    }
    return 1;
}

int ft_atoi(const char *str)
{
    int i;
    int num;
    int sign;

    i = 0;
    num = 0;
    sign = 1;
    while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
        i++;
    if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
    {
        sign *= -1;
        i++;
    }
    if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
        i++;
    while (str[i] > 47 && str[i] < 58)
    {
        num = (num * 10) + (str[i] - 48);
        i++;
    }
    return (num * sign);
}

void	ft_exit(char **arg)
{
	if (!*arg)
	{
		ft_putstr_fd("exit\n", 2);
		exit(0); // you have to exit with the exit_status and not 0
	}
	if (is_numeric(*arg) && *(arg + 1))
		ft_putstr_fd("exit: too many arguments\n", 2);
	else if (!is_numeric(*arg))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(*arg, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	else
	{
		ft_putstr_fd("exit\n", 2);
		exit(ft_atoi(*arg));
	}
}