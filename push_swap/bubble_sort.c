/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:37:07 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/25 18:42:19 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	copy(t_arg *va)
{
	int	i;

	i = 0;
	while (i < va->size_a)
	{
		va->s[i] = va->a[i];
		i++;
	}
}

void	bubble_sort(t_arg *va)
{
	int	i;
	int	j;
	int	swapped;

	copy(va);
	i = 0;
	while (i < va->size_s)
	{
		swapped = 0;
		j = 0;
		while (j < va->size_s - i - 1)
		{
			if (va->s[j] > va->s[j + 1])
			{
				sort(&va->s[j], &va->s[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}
