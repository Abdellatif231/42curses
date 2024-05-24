/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:36:46 by amaaouni          #+#    #+#             */
/*   Updated: 2023/12/29 07:10:44 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (len)
		{
			*(unsigned char *)(dst + len - 1) = *(unsigned char *)(src + len
					- 1);
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
