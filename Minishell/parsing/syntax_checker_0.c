/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:15:50 by bbelarra42        #+#    #+#             */
/*   Updated: 2024/09/27 12:02:14 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	quotes_red_checker(char *string)
{
	int		i;
	char	quote;
	int		closed;

	i = 0;
	closed = 1;
	while (string[i])
	{
		if (check_help(string, i, closed))
			return (0);
		if ((string[i] == 39 || string[i] == 34) && closed == 1)
		{
			if (string[i - 1] != '\\')
				closed = 0;
			quote = string[i];
		}
		else
		{
			if (string[i] == quote && string[i - 1] != '\\')
				closed = 1;
		}
		i++;
	}
	return (closed);
}

int	ampersand_checker(char *string, int *i, int closed)
{
	int	y;

	y = 0;
	if ((closed == 1 && string[y] == '&' && string[y - 1] != '\\'))
		return (1);
	return (0);
}

int	right_redirection_checker(char *string, int *i, int closed)
{
	int	y;
	int	reset;

	reset = 0;
	y = 0;
	if ((closed == 1 && string[y] == '>' && string[y - 1] != '\\'))
	{
		y++;
		(*i)++;
		reset++;
		if (string[y] == '>')
		{
			y++;
			(*i)++;
			reset++;
		}
		if (!string[y] || (string[y] == '>' && reset == 2))
			return (1);
		if (caller(string, y, i))
			return (1);
	}
	return (0);
}

int	pipe_checker(char *string, int *i, int closed)
{
	int	y;

	y = 0;
	if (closed == 1 && (*i) == 0 && string[y] == '|')
		return (1);
	if ((closed == 1 && string[y] == '|' && string[y - 1] != '\\'))
	{
		y++;
		(*i)++;
		while (string[y] == ' ' || string[y] == '|' || !string[y]
			|| string[y] == '&')
		{
			if ((string[y] == '\0') || (string[y] == '|' && string[y
						- 1] != '\\') || (string[y] == '&' && string[y
						- 1] != '\\'))
				return (1);
			y++;
			(*i)++;
		}
	}
	return (0);
}

int	syntax_checker(char *parse_string)
{
	if (!quotes_red_checker(parse_string))
		return (1);
	return (0);
}
