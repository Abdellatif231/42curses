/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:13:03 by amaaouni          #+#    #+#             */
/*   Updated: 2024/01/18 21:37:51 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_to_hex(unsigned long int n, char *base)
{
	int	count;

	count = 0;
	if (n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_conv_to_hex(n / 16, base);
		count += ft_conv_to_hex(n % 16, base);
	}
	return (count);
}

int	ft_putadr(void *p)
{
	unsigned long int	p_to_int;
	int					count;

	count = 0;
	p_to_int = (unsigned long int)p;
	count += ft_putstr("0x");
	count += ft_conv_to_hex(p_to_int, "0123456789abcdef");
	return (count);
}
