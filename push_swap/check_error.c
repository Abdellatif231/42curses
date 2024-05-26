/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:32:33 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/25 12:34:34 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(int ac, char *av[])
{
	int		count;
	int		i;
	char	**current_arg;
	char	**to_free;

	i = 1;
	count = 0;
	while (i < ac)
	{
		current_arg = ft_split(av[i], ' ');
		if (!current_arg)
			return (-1);
		to_free = current_arg;
		while (*to_free)
		{
			count++;
			to_free++;
		}
		free_split(current_arg);
		current_arg = NULL;
		i++;
	}
	return (count);
}

int	is_valid(char *str)
{
	int			i;
	long long	num;

	i = 0;
	if (*str == '\0' || (*str == '+' && *(str + 1) == '\0') || (*str == '-'
			&& *(str + 1) == '\0'))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (i != 0 || (str[i] != '+' && str[i] != '-')))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	has_dup(int *arr, int size)
{
	int	i;
	int	j;

	if (!arr)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	iterate(char *av[], t_arg *va)
{
	va->current_arg = ft_split(av[va->i], ' ');
	if (!va->current_arg)
		return (0);
	if (!*va->current_arg)
	{
		free(va->current_arg);
		return (0);
	}
	va->to_free = va->current_arg;
	while (*va->to_free)
	{
		if (!is_valid(*va->to_free))
		{
			free_split(va->current_arg);
			return (0);
		}
		va->numbers[va->num_index++] = ft_atoi(*va->to_free);
		va->to_free++;
	}
	free_split(va->current_arg);
	va->current_arg = NULL;
	return (1);
}

int	check_args(int ac, char *av[], t_arg *va)
{
	va->num_count = count_numbers(ac, av);
	if (!va->num_count)
	{
		free(va->current_arg);
		return (0);
	}
	va->numbers = malloc(va->num_count * sizeof(int));
	va->num_index = 0;
	va->i = 1;
	while (va->i < ac)
	{
		if (!av[va->i][0])
			return (0);
		if (!iterate(av, va))
			return (0);
		va->i++;
	}
	return (has_dup(va->numbers, va->num_count));
}
