/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <amaaouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:16:31 by amaaouni          #+#    #+#             */
/*   Updated: 2024/02/22 22:41:23 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(const char *s, va_list ptr)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (*s == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if (*s == 'd' || *s == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	else if (*s == 'x')
		count += ft_puthex(va_arg(ptr, int), "0123456789abcdef");
	else if (*s == 'X')
		count += ft_puthex(va_arg(ptr, int), "0123456789ABCDEF");
	else if (*s == 'u')
		count += ft_putunbr(va_arg(ptr, unsigned int));
	else if (*s == 'p')
		count += ft_putadr(va_arg(ptr, void *));
	else if (*s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!*s)
				return (count);
			count += print_format(s, ptr);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(ptr);
	return (count);
}
