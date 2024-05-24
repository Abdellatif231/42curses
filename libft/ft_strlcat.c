/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:24:55 by amaaouni          #+#    #+#             */
/*   Updated: 2023/12/26 22:25:12 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = 0;
	while (len_d < dstsize && dst[i])
	{
		len_d++;
		i++;
	}
	len_s = ft_strlen(src);
	if (len_d == dstsize)
		return (len_s + len_d);
	i = 0;
	while (src[i] != '\0' && len_d + i < dstsize - 1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
