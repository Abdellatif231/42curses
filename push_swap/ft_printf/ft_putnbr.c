/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:11:07 by amaaouni          #+#    #+#             */
/*   Updated: 2024/01/17 16:49:41 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n *= -1;
		}
		if (n < 10)
			count += ft_putchar(n + 48);
		else
		{
			count += ft_putnbr(n / 10);
			count += ft_putchar((n % 10) + 48);
		}
	}
	return (count);
}
