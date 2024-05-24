/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:50:34 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/15 13:16:20 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ptr_count(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if ((str[i] == c && str[i + 1] != c && str[i + 1]) || (str[i] == '\"'
				|| str[i] == '\''))
			count++;
		i++;
		if (!str[i])
			count++;
	}
	return (count);
}

char	**d_free(char **ary, int index)
{
	while (index >= 0)
	{
		free(ary[index]);
		index--;
	}
	free(ary);
	return (NULL);
}

char	*find_sub(const char *s, char *c, int *p_to_len)
{
	char		*array;
	const char	*ptr;
	size_t		end;

	end = 0;
	while (*s && *s == *c)
	{
		(*p_to_len)++;
		s++;
	}
	ptr = s;
	while (*s && *s != *c && *s != '\"' && *s != '\'')
	{
		s++;
		(*p_to_len)++;
		end++;
	}
	if (*s == '\"' || *s == '\'')
	{
		*c = *s;
		s++;
	}
	array = ft_substr(ptr, 0, end);
	return (array);
}

char	**split_command(char const *s, char c)
{
	char	**array;
	int		count;
	int		i;
	int		*p_to_len;
	int		len;

	p_to_len = &len;
	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = ptr_count(s, c);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	while (*s && count)
	{
		array[i] = find_sub(s + len, &c, p_to_len);
		if (!array[i])
			return (d_free(array, i));
		i++;
		count--;
	}
	array[i] = NULL;
	return (array);
}
