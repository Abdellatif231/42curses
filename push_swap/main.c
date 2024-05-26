/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:48:09 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/26 17:49:12 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_arg *va)
{
	if (va->size_a <= 3)
		sort_three(va);
	else if (va->size_a <= 5)
		sort_five(va);
	else if (va->size_a <= 100)
		sort_hundred(va);
	else
		sort_else(va);
}

int	main(int ac, char *av[])
{
	t_arg	va;

	if (ac == 1)
		return (0);
	if (!check_args(ac, av, &va))
	{
		if (va.numbers)
			free(va.numbers);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	va.a = va.numbers;
	va.b = malloc(va.num_count * sizeof(int));
	va.s = malloc(va.num_count * sizeof(int));
	va.size_a = va.num_count;
	va.size_s = va.num_count;
	va.size_b = 0;
	if (!is_sorted(&va))
		push_swap(&va);
	free(va.a);
	free(va.b);
	free(va.s);
	return (0);
}
