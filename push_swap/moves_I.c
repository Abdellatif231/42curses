/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_I.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:55:48 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/26 15:33:14 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int size)
{
	if (size < 2)
		return ;
	swap(a, size);
	write(1, "sa\n", 3);
}

void	sb(int *b, int size)
{
	if (size < 2)
		return ;
	swap(b, size);
	write(1, "ab\n", 3);
}

void	ss(int *a, int size_a, int *b, int size_b)
{
	if (size_a < 2 && size_b < 2)
		return ;
	swap(a, size_a);
	swap(b, size_b);
	write(1, "ss\n", 3);
}

void	pb(int *a, int *b, int *size_a, int *size_b)
{
	if (!*size_a)
		return ;
	push(a, b, size_a, size_b);
	write(1, "pb\n", 3);
}

void	pa(int *b, int *a, int *size_b, int *size_a)
{
	if (!*size_b)
		return ;
	push(b, a, size_b, size_a);
	write(1, "pa\n", 3);
}
