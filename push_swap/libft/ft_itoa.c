/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itao.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:03:26 by amaaouni          #+#    #+#             */
/*   Updated: 2023/12/29 06:36:22 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_char(int n)
{
	long	num;
	int		i;

	num = n;
	i = 1;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static long	revers_n(int n)
{
	long	rev_n;
	long	num;

	num = n;
	rev_n = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		rev_n *= 10;
		rev_n += num % 10;
		num /= 10;
	}
	return (rev_n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	alt_n;
	int		i;
	int		n_char;

	alt_n = revers_n(n);
	i = 0;
	n_char = num_of_char(n);
	ptr = malloc(sizeof(char) * n_char + 1);
	if (!ptr)
		return (0);
	if (n < 0)
	{
		ptr[i] = '-';
		i++;
	}
	while (i < n_char)
	{
		ptr[i] = alt_n % 10 + 48;
		alt_n /= 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
