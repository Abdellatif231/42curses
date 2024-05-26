/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:24:48 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/26 15:49:50 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct arg
{
	int		num_count;
	int		*numbers;
	int		*a;
	int		*b;
	int		*s;
	int		size_a;
	int		size_b;
	int		size_s;
	int		i;
	int		num_index;
	int		result;
	char	**current_arg;
	char	**to_free;
}			t_arg;

typedef struct sort
{
	int		small;
	int		larg;
	int		s_i;
	int		l_i;
}			t_sort;

typedef struct range
{
	int		start;
	int		end;
	int		index;
}			t_range;

void		rotate(int *a, int size);
void		rev_rotate(int *a, int size);
void		swap(int *a, int size);
void		push(int *from, int *to, int *from_size, int *to_size);
void		sa(int *a, int size);
void		sb(int *b, int size);
void		ss(int *a, int size_a, int *b, int size_b);
void		pa(int *b, int *a, int *size_b, int *size_a);
void		pb(int *a, int *b, int *size_a, int *size_b);
void		ra(int *a, int size);
void		rb(int *b, int size);
void		rr(int *a, int size_a, int *b, int size_b);
void		rra(int *a, int size);
void		rrb(int *b, int size);
void		rrr(int *a, int size_a, int *b, int size_b);
int			check_args(int ac, char *av[], t_arg *va);
int			free_split(char **arr);
void		sort_three(t_arg *va);
void		sort_five(t_arg *va);
int			is_sorted(t_arg *va);
void		bubble_sort(t_arg *va);
int			is_sorted(t_arg *va);
void		get_index(int *arr, int size, t_sort *so);
void		sort_hundred(t_arg *va);
void		range_sort(t_arg *va, t_range *rg);
void		sort_else(t_arg *va);

#endif
