/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:24:48 by amaaouni          #+#    #+#             */
/*   Updated: 2024/05/23 21:48:46 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct arg
{
	int	num_count;
	int	*numbers;
}		t_arg;

void	rotate(int *a, int size);
void	rev_rotate(int *a, int size);
void	swap(int *a, int size);
void	push(int *from, int *to, int *from_size, int *to_size);
void	sa(int *a, int size);
void	sb(int *b, int size);
void	ss(int *a, int size_a, int *b, int size_b);
void	pa(int *b, int *a, int *size_b, int *size_a);
void	pb(int *a, int *b, int *size_a, int *size_b);
void	ra(int *a, int size);
void	rb(int *b, int size);
void	rr(int *a, int size_a, int *b, int size_b);
void	rra(int *a, int size);
void	rrb(int *b, int size);
void	rrr(int *a, int size_a, int *b, int size_b);

#endif
