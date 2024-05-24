/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_I.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:55:48 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/22 21:38:48 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int size)
{
	swap(a, size);
	write(1, "sa\n", 3);
}

void	sb(int *b, int size)
{
	swap(b, size);
	write(1, "ab\n", 3);
}

void	ss(int *a, int size_a, int *b, int size_b)
{
	swap(a, size_a);
	swap(b, size_b);
	write(1, "ss\n", 3);
}

void	pb(int *b, int *a, int *size_b, int *size_a)
{
	push(b, a, size_b, size_a);
	write(1, "pb\n", 3);
}

void	pa(int *a, int *b, int *size_a, int *size_b)
{
	push(b, a, size_b, size_a);
	write(1, "pa\n", 3);
}
