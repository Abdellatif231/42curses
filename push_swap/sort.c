/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:35:05 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/26 15:50:09 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_arg *va)
{
	t_sort	so;

	get_index(va->a, va->size_a, &so);
	if (so.s_i == 1 && so.l_i == 0)
		ra(va->a, va->size_a);
	else if (so.s_i == 1 && so.l_i == 2)
		sa(va->a, va->size_a);
	else if (so.s_i == 2 && so.l_i == 0)
	{
		sa(va->a, va->size_a);
		rra(va->a, va->size_a);
	}
	else if (so.s_i == 2 && so.l_i == 1)
		rra(va->a, va->size_a);
	else if (so.s_i == 0 && so.l_i == 1)
	{
		sa(va->a, va->size_a);
		ra(va->a, va->size_a);
	}
}

void	sort_five(t_arg *va)
{
	void	(*f)(int *, int);
	t_sort	so;

	get_index(va->a, va->size_a, &so);
	if (so.s_i <= va->size_a / 2)
		f = &ra;
	else
		f = &rra;
	while (va->a[0] != so.small)
		f(va->a, va->size_a);
	pb(va->a, va->b, &va->size_a, &va->size_b);
	get_index(va->a, va->size_a, &so);
	if (so.s_i < va->size_a / 2)
		f = &ra;
	else
		f = &rra;
	while (va->a[0] != so.small)
		f(va->a, va->size_a);
	pb(va->a, va->b, &va->size_a, &va->size_b);
	sort_three(va);
	pa(va->b, va->a, &va->size_b, &va->size_a);
	pa(va->b, va->a, &va->size_b, &va->size_a);
}

void	sort_hundred(t_arg *va)
{
	t_range	rg;
	t_sort	so;
	void	(*f)(int *, int);

	rg.start = 0;
	rg.end = 15;
	bubble_sort(va);
	while (va->size_a)
		range_sort(va, &rg);
	while (va->size_b)
	{
		get_index(va->b, va->size_b, &so);
		if (so.l_i <= va->size_b / 2)
			f = &rb;
		else
			f = &rrb;
		while (va->b[0] != so.larg)
			f(va->b, va->size_b);
		pa(va->b, va->a, &va->size_b, &va->size_a);
	}
}

void	sort_else(t_arg *va)
{
	t_range	rg;
	t_sort	so;
	void	(*f)(int *, int);

	rg.start = 0;
	rg.end = 35;
	bubble_sort(va);
	while (va->size_a)
		range_sort(va, &rg);
	while (va->size_b)
	{
		get_index(va->b, va->size_b, &so);
		if (so.l_i <= va->size_b / 2)
			f = &rb;
		else
			f = &rrb;
		while (va->b[0] != so.larg)
			f(va->b, va->size_b);
		pa(va->b, va->a, &va->size_b, &va->size_a);
	}
}
