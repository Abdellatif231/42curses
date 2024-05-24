/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:10:43 by amaaouni          #+#    #+#             */
/*   Updated: 2023/12/30 01:14:36 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i])
	{
		if (set_check(set, s1[i]))
			i++;
		else
			break ;
	}
	if (s1[i] == '\0')
		return (ft_strdup(""));
	start = i;
	i = ft_strlen(s1) - 1;
	while (i)
	{
		if (set_check(set, s1[i]))
			i--;
		else
			break ;
	}
	return (ft_substr(s1, start, (i - start + 1)));
}
