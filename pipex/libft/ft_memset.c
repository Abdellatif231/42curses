/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:04:12 by amaaouni          #+#    #+#             */
/*   Updated: 2024/01/01 10:47:17 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pt;
	size_t			i;

	i = 0;
	pt = (unsigned char *)b;
	while (i < len)
	{
		pt[i] = (unsigned char)c;
		i++;
	}
	return ((void *)pt);
}
