/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:35:20 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/11 10:53:15 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*buffer;
	int			readed;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (ft_free(&static_buffer));
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (dubel_free(&buffer, &static_buffer));
		buffer[readed] = '\0';
		static_buffer = gnl_strjoin(static_buffer, buffer);
		if (!static_buffer)
			return (ft_free(&buffer));
		ft_free(&buffer);
		if (readed == 0 || newline_finder(static_buffer) != -1)
			break ;
	}
	if (static_buffer && gnl_strlen(static_buffer) == 0)
		return (ft_free(&static_buffer));
	return (buff_filter(&static_buffer, newline_finder(static_buffer)));
}

char	*buff_filter(char **str, int index)
{
	char	*line;
	char	*tmp;
	int		i;

	if (index == -1)
	{
		line = gnl_strdup(*str);
		ft_free(str);
		return (line);
	}
	tmp = *str;
	line = malloc(index + 2);
	if (!line)
		return (ft_free(str));
	i = 0;
	while (i <= index)
	{
		line[i++] = *tmp;
		tmp++;
	}
	line[i] = '\0';
	rest_of_line(str, index);
	return (line);
}

char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*dubel_free(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	*s1 = NULL;
	*s2 = NULL;
	return (NULL);
}

void	rest_of_line(char **str, int index)
{
	char	*rest;

	rest = gnl_strdup(*str + index + 1);
	free(*str);
	*str = rest;
}
