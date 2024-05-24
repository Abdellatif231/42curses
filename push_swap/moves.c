/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:55:44 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/23 18:42:42 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *a, int size)
{
	int	i;
	int	first_element;

	if (size <= 1)
	{
		return ;
	}
	first_element = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = first_element;
}

void	rev_rotate(int *a, int size)
{
	int	i;
	int	last_element;

	if (size <= 1)
	{
		return ;
	}
	last_element = a[size - 1];
	i = size - 1;
	while (i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = last_element;
}

void	swap(int *a, int size)
{
	int	temp;

	if (size < 2)
	{
		return ;
	}
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	push(int *from, int *to, int *from_size, int *to_size)
{
	to[*to_size] = from[0];
	(*to_size)++;
	rotate(from, *from_size);
	(*from_size)--;
	rev_rotate(to, *to_size);
}

void	rrr(int *a, int size_a, int *b, int size_b)
{
	rev_rotate(a, size_a);
	rev_rotate(b, size_b);
	write(1, "rrr\n", 4);
}
