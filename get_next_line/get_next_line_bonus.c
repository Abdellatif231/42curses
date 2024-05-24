/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:35:20 by amaaouni          #+#    #+#             */
/*   Updated: 2024/02/11 15:59:04 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*static_buffer[OPEN_MAX];
	char		*buffer;
	int			readed;

	if (BUFFER_SIZE <= 0 || fd >= OPEN_MAX || fd < 0)
		return (NULL);
	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (ft_free(&static_buffer[fd]));
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (dubel_free(&buffer, &static_buffer[fd]));
		buffer[readed] = '\0';
		static_buffer[fd] = ft_strjoin(static_buffer[fd], buffer);
		if (!static_buffer[fd])
			return (ft_free(&buffer));
		ft_free(&buffer);
		if (readed == 0 || newline_finder(static_buffer[fd]) != -1)
			break ;
	}
	if (static_buffer[fd] && ft_strlen(static_buffer[fd]) == 0)
		return (ft_free(&static_buffer[fd]));
	return (buff_filter(&static_buffer[fd], newline_finder(static_buffer[fd])));
}

char	*buff_filter(char **str, int index)
{
	char	*line;
	char	*tmp;
	int		i;

	if (index == -1)
	{
		line = ft_strdup(*str);
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

	rest = ft_strdup(*str + index + 1);
	free(*str);
	*str = rest;
}
