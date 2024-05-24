/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:32:33 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/23 21:57:12 by amaaouni         ###   ########.fr       */
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
	if (str[0] == '0' && str[1] != '\0')
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

int	check_args(int ac, char *av[], t_arg *va)
{
	int		i;
	int		num_index;
	int		result;
	char	**current_arg;
	char	**to_free;

	va->num_count = count_numbers(ac, av);
	va->numbers = malloc(va->num_count * sizeof(int));
	num_index = 0;
	i = 1;
	while (i < ac)
	{
		current_arg = ft_split(av[i], ' ');
		if (!current_arg)
			return (0);
		to_free = current_arg;
		while (*to_free)
		{
			if (!is_valid(*to_free))
			{
				free_split(current_arg);
				free(va->numbers);
				va->numbers = NULL;
				return (0);
			}
			va->numbers[num_index++] = ft_atoi(*to_free);
			to_free++;
		}
		free_split(current_arg);
		current_arg = NULL;
		i++;
	}

	result = has_dup(va->numbers, va->num_count);
	if (!result)
		free(va->numbers);
	return result;
}

void	leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int ac, char *av[])
{
	t_arg	va;
	int		i;

	atexit(leaks);
	if (!check_args(ac, av, &va))
	{
		ft_printf("Error\n");
		return (1);
	}
	else
		ft_printf("Done\n");
	ft_printf(">>%d\n", va.num_count);
	if (va.numbers)
	{
		i = 0;
		while (i < va.num_count)
		{
			ft_printf("%d\n", va.numbers[i]);
			i++;
		}
	}
	free(va.numbers);
	return (0);
}
