/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:35:58 by amaaouni          #+#    #+#             */
/*   Updated: 2024/01/17 16:49:23 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_puthex(n / 16, base);
		count += ft_puthex(n % 16, base);
	}
	return (count);
}
