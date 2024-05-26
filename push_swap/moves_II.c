/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:56:50 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/26 15:36:39 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a, int size)
{
	if (size < 2)
		return ;
	rotate(a, size);
	write(1, "ra\n", 3);
}

void	rb(int *b, int size)
{
	if (size < 2)
		return ;
	rotate(b, size);
	write(1, "rb\n", 3);
}

void	rr(int *a, int size_a, int *b, int size_b)
{
	if (size_a < 2 && size_b < 2)
		return ;
	rotate(a, size_a);
	rotate(b, size_b);
	write(1, "rr\n", 3);
}

void	rra(int *a, int size)
{
	if (size < 2)
		return ;
	rev_rotate(a, size);
	write(1, "rra\n", 4);
}

void	rrb(int *b, int size)
{
	if (size < 2)
		return ;
	rev_rotate(b, size);
	write(1, "rrb\n", 4);
}
