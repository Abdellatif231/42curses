/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:39:43 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/26 15:05:28 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_split(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
	return (1);
}

int	is_sorted(t_arg *va)
{
	int	i;

	i = 0;
	while (i < va->size_a - 1)
	{
		if (va->a[i] > va->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	get_index(int *arr, int size, t_sort *so)
{
	int	i;

	so->larg = arr[size - 1];
	so->l_i = size - 1;
	so->small = arr[0];
	so->s_i = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > so->larg)
		{
			so->larg = arr[i];
			so->l_i = i;
		}
		else if (arr[i] < so->small)
		{
			so->small = arr[i];
			so->s_i = i;
		}
		i++;
	}
}

void	move_range(t_range *rg)
{
	rg->start++;
	rg->end++;
}

void	range_sort(t_arg *va, t_range *rg)
{
	int	j;

	j = 0;
	while (j < va->size_s)
	{
		if (va->a[0] == va->s[j])
		{
			rg->index = j;
			break ;
		}
		j++;
	}
	if (rg->index >= rg->start && rg->index <= rg->end)
	{
		pb(va->a, va->b, &va->size_a, &va->size_b);
		move_range(rg);
	}
	else if (rg->index < rg->start)
	{
		pb(va->a, va->b, &va->size_a, &va->size_b);
		rb(va->b, va->size_b);
		move_range(rg);
	}
	else
		ra(va->a, va->size_a);
}
