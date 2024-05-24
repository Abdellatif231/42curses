/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_II.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:33:14 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/16 12:38:28 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_empty(t_par *var)
{
	if (var->arr[var->i][0] != '\0' &&
		!(var->arr[var->i][0] == ' ' && var->arr[var->i][1] == '\0'))
	{
		*(var->tmp) = ft_strdup(var->arr[var->i]);
		var->tmp++;
	}
	var->i++;
}

char	**final_split(char *str, char c)
{
	t_par	var;

	var.i = 0;
	var.count = 0;
	var.arr = split_command(str, c);
	while (var.arr[var.i])
	{
		if (var.arr[var.i][0] != '\0' ||
			!(var.arr[var.i][0] == ' ' && var.arr[var.i][1] == '\0'))
			var.count++;
		var.i++;
	}
	var.final = malloc(sizeof(char *) * (var.count + 1));
	var.tmp = var.final;
	var.i = 0;
	while (var.arr[var.i])
		check_empty(&var);
	*(var.tmp) = NULL;
	free_split(var.arr);
	return (var.final);
}

int	free_split(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
	return (1);
}
